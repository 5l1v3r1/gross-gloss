#ifndef SCENES_GEN_H
#define SCENES_GEN_H

#define t_graffiti (0.0)
#define t_groundboxes (49.655)
#define t_voronoidesign (82.76)
#define t_bloodcells (99.31)
const double start_times[] = {
t_graffiti,
t_groundboxes,
t_voronoidesign,
t_bloodcells
};
const char *scene_names[] = {
"Graffiti illusion",
"Boxes on the ground",
"Voronoi valley",
"Blood cells"
};
const unsigned int nscenes = ARRAYSIZE(start_times);
// We need these two arrays to always have the same size - the following line will cause a compiler error if this is ever not the case
_STATIC_ASSERT(ARRAYSIZE(start_times) == ARRAYSIZE(scene_names));
#endif