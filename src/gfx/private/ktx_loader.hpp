#pragma once
#include <sokol_gfx.h>

namespace ari
{
    namespace core
    {
        class Buffer;
    }

    namespace gfx
    {
        void LoadKtxTexture(sg_image img, core::Buffer* buffer);
    }

} // namespace ari
