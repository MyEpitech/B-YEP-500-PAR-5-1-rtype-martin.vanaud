/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CAssetId
*/

#ifndef CASSETID_HPP_
    #define CASSETID_HPP_

    #include <string>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing asset id from asset manager
     */
    struct cassetid_t {
        std::string assets; ///< asset string to find in asset list
    };
}

#endif /* !CASSETID_HPP_ */
