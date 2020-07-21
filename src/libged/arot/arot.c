/*                         A R O T . C
 * BRL-CAD
 *
 * Copyright (c) 2008-2020 United States Government as represented by
 * the U.S. Army Research Laboratory.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this file; see the file named COPYING for more
 * information.
 */
/** @file libged/arot.c
 *
 * The arot command.
 *
 */

#include "common.h"

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../ged_private.h"

int
ged_arot_args(struct ged *gedp, int argc, const char *argv[], mat_t rmat)
{
    point_t pt = VINIT_ZERO;
    vect_t axisv;
    double axis[3]; /* not fastf_t due to sscanf */
    double angle; /* not fastf_t due to sscanf */
    static const char *usage = "x y z angle";

    GED_CHECK_DATABASE_OPEN(gedp, GED_ERROR);
    GED_CHECK_VIEW(gedp, GED_ERROR);
    GED_CHECK_ARGC_GT_0(gedp, argc, GED_ERROR);

    /* initialize result */
    bu_vls_trunc(gedp->ged_result_str, 0);

    /* must be wanting help */
    if (argc == 1) {
	bu_vls_printf(gedp->ged_result_str, "Usage: %s %s", argv[0], usage);
	return GED_HELP;
    }

    if (argc != 5) {
	bu_vls_printf(gedp->ged_result_str, "Usage: %s %s", argv[0], usage);
	return GED_ERROR;
    }

    if (sscanf(argv[1], "%lf", &axis[X]) != 1) {
	bu_vls_printf(gedp->ged_result_str, "%s: bad X value - %s\n", argv[0], argv[1]);
	return GED_ERROR;
    }

    if (sscanf(argv[2], "%lf", &axis[Y]) != 1) {
	bu_vls_printf(gedp->ged_result_str, "%s: bad Y value - %s\n", argv[0], argv[2]);
	return GED_ERROR;
    }

    if (sscanf(argv[3], "%lf", &axis[Z]) != 1) {
	bu_vls_printf(gedp->ged_result_str, "%s: bad Z value - %s\n", argv[0], argv[3]);
	return GED_ERROR;
    }

    if (sscanf(argv[4], "%lf", &angle) != 1) {
	bu_vls_printf(gedp->ged_result_str, "%s: bad angle - %s\n", argv[0], argv[4]);
	return GED_ERROR;
    }

    VUNITIZE(axis);
    VMOVE(axisv, axis);
    bn_mat_arb_rot(rmat, pt, axisv, angle*DEG2RAD);

    return GED_OK;
}


int
ged_arot(struct ged *gedp, int argc, const char *argv[])
{
    int ret;
    mat_t rmat;

    if ((ret = ged_arot_args(gedp, argc, argv, rmat)) != GED_OK)
	return ret;

    return _ged_do_rot(gedp, gedp->ged_gvp->gv_coord, rmat, (int (*)())0);
}


#ifdef GED_PLUGIN
#include "../include/plugin.h"
struct ged_cmd_impl arot_cmd_impl = {
    "arot",
    ged_arot,
    GED_CMD_DEFAULT
};

const struct ged_cmd arot_cmd = { &arot_cmd_impl };
const struct ged_cmd *arot_cmds[] = { &arot_cmd, NULL };

static const struct ged_plugin pinfo = { arot_cmds, 1 };

COMPILER_DLLEXPORT const struct ged_plugin *ged_plugin_info()
{
    return &pinfo;
}
#endif /* GED_PLUGIN */

/*
 * Local Variables:
 * mode: C
 * tab-width: 8
 * indent-tabs-mode: t
 * c-file-style: "stroustrup"
 * End:
 * ex: shiftwidth=4 tabstop=8
 */