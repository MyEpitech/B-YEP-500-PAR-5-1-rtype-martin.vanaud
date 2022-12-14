/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Shoot
*/

#ifndef SHOOT_HPP_
    #define SHOOT_HPP_

    #include <cstdint>

    /**
     * @brief A packet to handle a bullet shot by an entity
     */
    struct packet_shoot {
        uint16_t id; ///< id of the entity that is shooting
    };

    /**
     * @brief A packet to handle the direction that an entity is looking at
     */
    struct packet_direction {
        uint16_t orientation; ///< 1:NORTH;2:EAST;3:SOUTH;4:WEST
    };


#endif /* !SHOOT_HPP_ */
