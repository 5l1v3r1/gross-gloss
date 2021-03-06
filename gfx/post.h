/* Generated with shader-compressor by NR4/Team210. */
#ifndef POST_H
#define POST_H
const char * post_frag =
"/* Endeavor by Team210 - 64k intro by Team210 at Revision 2k19\n"
" * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>\n"
" *\n"
" * This program is free software: you can redistribute it and/or modify\n"
" * it under the terms of the GNU General Public License as published by\n"
" * the Free Software Foundation, either version 3 of the License, or\n"
" * (at your option) any later version.\n"
" *\n"
" * This program is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
" * GNU General Public License for more details.\n"
" *\n"
" * You should have received a copy of the GNU General Public License\n"
" * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n"
" */\n"
" \n"
"#version 130\n"
"\n"
"uniform float iFSAA;\n"
"uniform vec2 iResolution;\n"
"uniform sampler2D iChannel0;\n"
"uniform float iTime;\n"
"\n"
"out vec4 gl_FragColor;\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"float nbeats;\n"
"float iScale;\n"
"\n"
"void rand(in vec2 x, out float n)\n"
"{\n"
"    x += 400.;\n"
"    n = fract(sin(dot(sign(x)*abs(x) ,vec2(12.9898,78.233)))*43758.5453);\n"
"}\n"
"\n"
"void mainImage( out vec4 fragColor, in vec2 fragCoord_ )\n"
"{\n"
"    vec2 fragCoord = fragCoord_;\n"
"    float a = iResolution.x/iResolution.y;\n"
"    vec2 uv = fragCoord/iResolution.yy-0.5*vec2(a, 1.0);\n"
"    \n"
"    vec3 col = vec3(0.);\n"
"    float delta = 0.;\n"
"    vec2 n = c.yy;\n"
"    \n"
"    if(iTime > 66.27 && iTime < 82.76) // blend in to caleidoscope\n"
"    {\n"
"        n = vec2(7.,1.);\n"
"        float phi = abs(mod(atan(uv.y, uv.x),pi/n.x)-.5*pi/n.x);\n"
"        uv = length(uv)*vec2(cos(phi+2.*pi), sin(phi+2.*pi));\n"
"        fragCoord = mix(fragCoord, (uv + .5*vec2(a,1.))*iResolution.yy, smoothstep(66.27,67.27,iTime)*(1.-smoothstep(81.76,82.76,iTime)));\n"
"    }\n"
"    else if(iTime > 120.0 && iTime < 136.0) // blend in to caleidoscope\n"
"    {\n"
"        n = vec2(7.,1.);\n"
"        float phi = abs(mod(atan(uv.y, uv.x),pi/n.x)-.5*pi/n.x);\n"
"        uv = length(uv)*vec2(cos(phi+2.*pi), sin(phi+2.*pi));\n"
"        fragCoord = mix(fragCoord, (uv + .5*vec2(a,1.))*iResolution.yy, smoothstep(120.,121.,iTime)*(1.-smoothstep(135.,136.,iTime)));\n"
"    }\n"
"    \n"
"    float bound = sqrt(iFSAA)-1.;\n"
"//     bound = mix(bound, 4., smoothstep(66.27,67.27,iTime)*(1.-smoothstep(81.76,82.76,iTime)));\n"
"    \n"
"    if((iTime > 66.27 && iTime < 82.76) || (iTime > 120.0 && iTime < 136.0))\n"
"    {\n"
"        for(float i = -.5*bound; i<=.5*bound; i+=1.)\n"
"            for(float j=-.5*bound; j<=.5*bound; j+=1.)\n"
"            {\n"
"                col += texture(iChannel0, fragCoord/iResolution.xy+vec2(i,j)*3./max(bound, 1.)/iResolution.xy).xyz;\n"
"            }\n"
"        col /= iFSAA;\n"
"    }\n"
"    else\n"
"    {\n"
"        for(float i = -.5*bound; i<=.5*bound; i+=1.)\n"
"            for(float j=-.5*bound; j<=.5*bound; j+=1.)\n"
"            {\n"
"                col += texture(iChannel0, fragCoord/iResolution.xy+vec2(i,j)*mix(3.,15.,2.*abs(fragCoord.y/iResolution.y-.5))*exp(-abs(1.e-2*length(fragCoord.xy)/iResolution.y-.5))/max(bound, 1.)/iResolution.xy).xyz;\n"
"            }\n"
"        col /= iFSAA;\n"
"    }\n"
"    fragColor = vec4(col,1.0);\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    mainImage(gl_FragColor, gl_FragCoord.xy);\n"
"}\n"
"\n"
;
#endif
