#ifndef DRAW_GEN_H
#define DRAW_GEN_H
if(t < t_groundboxes)
{
    glUseProgram(shader_program_gfx_graffiti.handle);
    glUniform1f(shader_uniform_gfx_graffiti_iTime, t - t_graffiti);
    glUniform2f(shader_uniform_gfx_graffiti_iResolution, w, h);
#ifdef MIDI
    glUniform1f(shader_uniform_gfx_graffiti_iFader0, fader0);
    glUniform1f(shader_uniform_gfx_graffiti_iFader1, fader1);
    glUniform1f(shader_uniform_gfx_graffiti_iFader2, fader2);
    glUniform1f(shader_uniform_gfx_graffiti_iFader3, fader3);
    glUniform1f(shader_uniform_gfx_graffiti_iFader4, fader4);
    glUniform1f(shader_uniform_gfx_graffiti_iFader5, fader5);
    glUniform1f(shader_uniform_gfx_graffiti_iFader6, fader6);
    glUniform1f(shader_uniform_gfx_graffiti_iFader7, fader7);
#endif
}
else if(t < t_voronoidesign)
{
    glUseProgram(shader_program_gfx_groundboxes.handle);
    glUniform1f(shader_uniform_gfx_groundboxes_iTime, t - t_groundboxes);
    glUniform2f(shader_uniform_gfx_groundboxes_iResolution, w, h);
#ifdef MIDI
    glUniform1f(shader_uniform_gfx_groundboxes_iFader0, fader0);
    glUniform1f(shader_uniform_gfx_groundboxes_iFader1, fader1);
    glUniform1f(shader_uniform_gfx_groundboxes_iFader2, fader2);
    glUniform1f(shader_uniform_gfx_groundboxes_iFader3, fader3);
    glUniform1f(shader_uniform_gfx_groundboxes_iFader4, fader4);
    glUniform1f(shader_uniform_gfx_groundboxes_iFader5, fader5);
    glUniform1f(shader_uniform_gfx_groundboxes_iFader6, fader6);
    glUniform1f(shader_uniform_gfx_groundboxes_iFader7, fader7);
#endif
}
else if(t < t_bloodcells)
{
    glUseProgram(shader_program_gfx_voronoidesign.handle);
    glUniform1f(shader_uniform_gfx_voronoidesign_iTime, t - t_voronoidesign);
    glUniform2f(shader_uniform_gfx_voronoidesign_iResolution, w, h);
#ifdef MIDI
    glUniform1f(shader_uniform_gfx_voronoidesign_iFader0, fader0);
    glUniform1f(shader_uniform_gfx_voronoidesign_iFader1, fader1);
    glUniform1f(shader_uniform_gfx_voronoidesign_iFader2, fader2);
    glUniform1f(shader_uniform_gfx_voronoidesign_iFader3, fader3);
    glUniform1f(shader_uniform_gfx_voronoidesign_iFader4, fader4);
    glUniform1f(shader_uniform_gfx_voronoidesign_iFader5, fader5);
    glUniform1f(shader_uniform_gfx_voronoidesign_iFader6, fader6);
    glUniform1f(shader_uniform_gfx_voronoidesign_iFader7, fader7);
#endif
}
else {
    glUseProgram(shader_program_gfx_bloodcells.handle);
    glUniform1f(shader_uniform_gfx_bloodcells_iTime, t - t_bloodcells);
    glUniform2f(shader_uniform_gfx_bloodcells_iResolution, w, h);
#ifdef MIDI
    glUniform1f(shader_uniform_gfx_bloodcells_iFader0, fader0);
    glUniform1f(shader_uniform_gfx_bloodcells_iFader1, fader1);
    glUniform1f(shader_uniform_gfx_bloodcells_iFader2, fader2);
    glUniform1f(shader_uniform_gfx_bloodcells_iFader3, fader3);
    glUniform1f(shader_uniform_gfx_bloodcells_iFader4, fader4);
    glUniform1f(shader_uniform_gfx_bloodcells_iFader5, fader5);
    glUniform1f(shader_uniform_gfx_bloodcells_iFader6, fader6);
    glUniform1f(shader_uniform_gfx_bloodcells_iFader7, fader7);
#endif
}
#endif
