/*
 * Capability
 *
 * Author: Udo Steinberg <udo@hypervisor.org>
 * TU Dresden, Operating Systems Group
 *
 * This file is part of the NOVA microhypervisor.
 *
 * NOVA is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * NOVA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License version 2 for more details.
 */

#pragma once

#include "compiler.h"

class Kobject;

class Capability
{
    private:
        mword val;

        static unsigned const mask = 0x7;

    public:
        Capability() : val (0) {}

        Capability (Kobject *o, unsigned a = mask) : val (reinterpret_cast<mword>(o) | a) {}

        ALWAYS_INLINE
        inline Kobject *obj() const { return reinterpret_cast<Kobject *>(val & ~mask); }

        ALWAYS_INLINE
        inline unsigned acc() const { return val & mask; }
};
