/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CNetworkQueue
*/

#ifndef CNETWORKQUEUE_HPP_
    #define CNETWORKQUEUE_HPP_

    #include <queue>

    #include "Move.hpp"

using byte = unsigned char;

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the queue use by the ECS to send the request to the server
     */
    typedef struct cnetwork_queue_s {
        std::queue<std::vector<byte>> receivedNetworkQueue;
        std::queue<std::vector<byte>> toSendNetworkQueue;

        std::queue<packet_move> moveQueue;
        // std::queue<> shootQueue;
        // std::queue<> newPlayerQueue;


    } cnetwork_queue_t;
}

#endif /* !CNETWORKQUEUE_HPP_ */