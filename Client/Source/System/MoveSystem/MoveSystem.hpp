/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MoveSystem
*/

#ifndef MOVESYSTEM_HPP_
#define MOVESYSTEM_HPP_

#include "Registry.hpp"

#include "CNetworkQueue.hpp"
#include "CDirection.hpp"
#include "CPosition.hpp"
#include "CVelocity.hpp"

class MoveSystem {
    public:
        MoveSystem();

        ~MoveSystem() = default;

        void operator()(Registry &registry,
                        Sparse_array<component::cnetwork_queue_t> &netqueue,
                        Sparse_array<component::cdirection_t> &direction,
                        Sparse_array<component::cposition_t> &position,
                        Sparse_array<component::cvelocity_t> &velocity);

    protected:

    private:
};

#endif /* !MOVESYSTEM_HPP_ */