#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "../World/Block/BlockId.h"
#include <string>

#include "../Util/NonCopyable.h"

/// @brief Determines case-by-case properties and behaviors of known block types.
struct Material : public NonCopyable {
    enum ID {
        Nothing,
        Grass,
        Dirt,
        Stone,
        OakBark,
        OakLeaf,
        Sand,
        Cactus,
        Rose,
        TallGrass,
        DeadShrub
    };

    const static Material NOTHING;
    const static Material GRASS_BLOCK;
    const static Material DIRT_BLOCK;
    const static Material STONE_BLOCK;
    const static Material OAK_BARK_BLOCK;
    const static Material OAK_LEAF_BLOCK;
    const static Material SAND_BLOCK;
    const static Material CACTUS_BLOCK;
    const static Material ROSE;
    const static Material TALL_GRASS;
    const static Material DEAD_SHRUB;

    Material(Material::ID id, int maxStack, bool isBlock, std::string &&name);

    BlockId toBlockID() const;

    static const Material &toMaterial(BlockId id);

    const Material::ID id;
    const int maxStackSize;
    const bool isBlock;
    const std::string name;
};

namespace std {
template <> struct hash<Material::ID> {
    size_t operator()(const Material::ID &id) const
    {
        std::hash<Material::ID> hasher;

        return hasher(id);
    }
};
} // namespace std

#endif // MATERIAL_H_INCLUDED
