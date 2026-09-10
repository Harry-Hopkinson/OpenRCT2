/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../tile_element/Segment.h"

#include <cstdint>

namespace OpenRCT2::BlockedSegments
{
    constexpr PaintSegments kStraightFlat(PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft);
    constexpr PaintSegments kDiagStraightFlat[] = {
        PaintSegments(PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight, PaintSegment::right),
        PaintSegments(PaintSegment::centre, PaintSegment::topRight, PaintSegment::topLeft, PaintSegment::top),
        PaintSegments(PaintSegment::bottomLeft, PaintSegment::centre, PaintSegment::bottom, PaintSegment::bottomRight),
        PaintSegments(PaintSegment::bottomLeft, PaintSegment::centre, PaintSegment::left, PaintSegment::topLeft),
    };
} // namespace OpenRCT2::BlockedSegments
