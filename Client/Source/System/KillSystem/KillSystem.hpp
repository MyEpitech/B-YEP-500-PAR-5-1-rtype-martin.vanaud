/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillSystem
*/

#ifndef KILLSYSTEM_HPP_
    #define KILLSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Graphical Lib */
    #include "GraphicalLib.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CServerId.hpp"
    #include "Component/CType.hpp"
    #include "Component/CSound.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief KillSystem class that handles the killing of entities
     */
    class KillSystem {
        public:
            /**
             * @brief Construct a new Kill System object
             */
            KillSystem();
            ~KillSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param network The sparse array of network entities
             * @param serverId The sparse array of serverId entities
             * @param type The sparse array of type entities
             * @param sounds The sparse array of sound entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &network,
                Sparse_array<component::cserverid_t> &serverId,
                Sparse_array<component::ctype_t> &type,
                Sparse_array<component::csound_t> &sounds);

            /**
             * @brief A method to kill an entity
             *
             * @param registry The registry of the client
             * @param id The id of the entity to kill
             * @param serverId The sparse array of serverId entities
             */
            void killEntity(Registry &registry,
                            std::size_t id,
                            Sparse_array<component::cserverid_t> &serverId,
                            Sparse_array<component::ctype_t> &type,
                            Sparse_array<component::csound_t> &sounds);

        protected:
        private:
            std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
    };
}

#endif /* !KILLSYSTEM_HPP_ */
