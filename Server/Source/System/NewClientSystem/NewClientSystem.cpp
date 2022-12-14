/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** NewClientSystem
*/

#include "NewClientSystem.hpp"

/* Constant */
#include "Constant.hpp"

/* Serialization */
#include "Serialization.hpp"

/* Packets */
#include "Lobbies.hpp"
#include "NewConnection.hpp"

/* Components */
#include "Component/CLobbyId.hpp"
#include "Component/CDisconnected.hpp"

System::NewClientSystem::NewClientSystem() {
}

void System::NewClientSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities) {
        // std::cout << "NewClientSystem" << std::endl;
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().newPlayerQueue.empty()) {
        std::pair<int, packet_new_connection> &newConnect = netqueue[FORBIDDEN_IDS::NETWORK].value().newPlayerQueue.front();

        // CREATE A CLIENT ENTITY
        Entity newClient = registry.spawn_entity_with(
            component::cnetwork_id_t { .id = newConnect.second.id }, // ADD A NETWORK ID TO CLIENT ENTITY
            component::clobby_id_t { .id = 0 }, // GIVE A LOBBY ID WHERE THE CLIENT IS
            component::cdisconnected_t { .isDisconnected = false } // GIVE BOOLEAN TO KNOW IF THE CLIENT IS DISCONNECTING
        );

        std::cout << "New client System : network client id:  " << newConnect.second.id << std::endl;

        netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.try_emplace(newConnect.second.id, newClient);
        lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(0).push_back(newClient);

        netqueue[FORBIDDEN_IDS::NETWORK].value().newPlayerQueue.pop();
        sendLobbiesStatus(newClient, netqueue, lobbiesToEntities);
        // for (auto &[netId, clientId]: netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId)
        //     std::cout << "[CLIENT] ids: " << netId << ", " << clientId << std::endl;
    }
}

void System::NewClientSystem::sendLobbiesStatus(int clientId, Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities) {
    packet_send_lobbies sendLobbiesPacket;

    sendLobbiesPacket.nbOfLobbies = 3;
    sendLobbiesPacket.nbPlayersLobbyOne = lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(1).size();
    sendLobbiesPacket.nbPlayersLobbyTwo = lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(2).size();
    sendLobbiesPacket.nbPlayersLobbyThree = lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(3).size();

    packet_new_connection_response newConnectResponse;
    newConnectResponse.id = clientId;
    networkQueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(std::pair<int, std::vector<byte>>(0, serialize_header::serializeHeader<packet_new_connection_response>(NETWORK_SERVER_TO_CLIENT::NEW_CLIENT_RESPONSE, newConnectResponse)));
    std::cout << " New client system : send Lobbies status : new client ecs id :  "<< clientId << std::endl;
    networkQueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(std::pair<int, std::vector<byte>>(0, serialize_header::serializeHeader<packet_send_lobbies>(NETWORK_SERVER_TO_CLIENT::SEND_LOBBYS, sendLobbiesPacket)));
}