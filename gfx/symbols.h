//Generated with Symbolize (c) 2019 Alexander Kraus <nr4@z10.info>.
#ifndef SYMBOLIZE_H
#define SYMBOLIZE_H

int rand_handle, lfnoise_handle, mfnoise_handle, stroke_handle, add_handle, dvoronoi_handle, normal_handle, rot3_handle, dbox_handle, dlinesegment3_handle, zextrude_handle;
const int nsymbols = 11;
const char *rand_source = "#version 130\n\n"
"void rand(in vec2 x, out float n)\n"
"{\n"
"    x += 400.;\n"
"    n = fract(sin(dot(sign(x)*abs(x) ,vec2(12.9898,78.233)))*43758.5453);\n"
"}\n"
"\0";
const char *lfnoise_source = "#version 130\n\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"void rand(in vec2 x, out float d);\n"
"void lfnoise(in vec2 t, out float n)\n"
"{\n"
"    vec2 i = floor(t);\n"
"    t = fract(t);\n"
"    t = smoothstep(c.yy, c.xx, t);\n"
"    vec2 v1, v2;\n"
"    rand(i, v1.x);\n"
"    rand(i+c.xy, v1.y);\n"
"    rand(i+c.yx, v2.x);\n"
"    rand(i+c.xx, v2.y);\n"
"    v1 = c.zz+2.*mix(v1, v2, t.y);\n"
"    n = mix(v1.x, v1.y, t.x);\n"
"}\n"
"\0";
const char *mfnoise_source = "#version 130\n\n"
"// const vec3 c = vec3(1.,0.,-1.);\n"
"void lfnoise(in vec2 x, out float d);\n"
"void mfnoise(in vec2 x, in float d, in float b, in float e, out float n)\n"
"{\n"
"    n = 0.;\n"
"    float a = 1., nf = 0., buf;\n"
"    for(float f = d; f<b; f *= 2.)\n"
"    {\n"
"        lfnoise(f*x, buf);\n"
"        n += a*buf;\n"
"        a *= e;\n"
"        nf += 1.;\n"
"    }\n"
"    n *= (1.-e)/(1.-pow(e, nf));\n"
"}\n"
"\0";
const char *stroke_source = "// Stroke\n"
"void stroke(in float d0, in float s, out float d)\n"
"{\n"
"    d = abs(d0)-s;\n"
"}\n"
"\0";
const char *add_source = "void add(in vec2 sda, in vec2 sdb, out vec2 sdf)\n"
"{\n"
"    sdf = mix(sda, sdb, step(sdb.x, sda.x));\n"
"}\n"
"\0";
const char *dvoronoi_source = "#version 130\n\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"void rand(in vec2 x, out float d);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 z)\n"
"{\n"
"    vec2 y = floor(x);\n"
"       float ret = 1.;\n"
"    vec2 pf=c.yy, p;\n"
"    float df=10.;\n"
"    \n"
"    for(int i=-1; i<=1; i+=1)\n"
"        for(int j=-1; j<=1; j+=1)\n"
"        {\n"
"            p = y + vec2(float(i), float(j));\n"
"            float pa;\n"
"            rand(p, pa);\n"
"            p += pa;\n"
"            \n"
"            d = length(x-p);\n"
"            \n"
"            if(d < df)\n"
"            {\n"
"                df = d;\n"
"                pf = p;\n"
"            }\n"
"        }\n"
"    for(int i=-1; i<=1; i+=1)\n"
"        for(int j=-1; j<=1; j+=1)\n"
"        {\n"
"            p = y + vec2(float(i), float(j));\n"
"            float pa;\n"
"            rand(p, pa);\n"
"            p += pa;\n"
"            \n"
"            vec2 o = p - pf;\n"
"            d = length(.5*o-dot(x-pf, o)/dot(o,o)*o);\n"
"            ret = min(ret, d);\n"
"        }\n"
"    \n"
"    d = ret;\n"
"    z = pf;\n"
"}\n"
"\0";
const char *normal_source = "const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"void scene(in vec3 x, out vec2 s);\n"
"void normal(in vec3 x, out vec3 n, in float dx)\n"
"{\n"
"    vec2 s, na;\n"
"    \n"
"    scene(x,s);\n"
"    scene(x+dx*c.xyy, na);\n"
"    n.x = na.x;\n"
"    scene(x+dx*c.yxy, na);\n"
"    n.y = na.x;\n"
"    scene(x+dx*c.yyx, na);\n"
"    n.z = na.x;\n"
"    n = normalize(n-s.x);\n"
"}\n"
"\0";
const char *rot3_source = "const vec3 c = vec3(1.,0.,-1.);\n"
"void rot3(in vec3 p, out mat3 rot)\n"
"{\n"
"    rot = mat3(c.xyyy, cos(p.x), sin(p.x), 0., -sin(p.x), cos(p.x))\n"
"        *mat3(cos(p.y), 0., -sin(p.y), c.yxy, sin(p.y), 0., cos(p.y))\n"
"        *mat3(cos(p.z), -sin(p.z), 0., sin(p.z), cos(p.z), c.yyyx);\n"
"}\n"
"\0";
const char *dbox_source = "#version 130\n\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"void dbox(in vec2 x, in vec2 b, out float d)\n"
"{\n"
"    vec2 da = abs(x)-b;\n"
"    d = length(max(da,c.yy)) + min(max(da.x,da.y),0.0);\n"
"}\n"
"\0";
const char *dlinesegment3_source = "#version 130\n\n"
"void dlinesegment3(in vec3 x, in vec3 p1, in vec3 p2, out float d)\n"
"{\n"
"    vec3 da = p2-p1;\n"
"    d = length(x-mix(p1, p2, clamp(dot(x-p1, da)/dot(da,da),0.,1.)));\n"
"}\n"
"\0";
const char *zextrude_source = "// Extrusion\n"
"void zextrude(in float z, in float d2d, in float h, out float d)\n"
"{\n"
"    vec2 w = vec2(-d2d, abs(z)-0.5*h);\n"
"    d = length(max(w,0.0));\n"
"}\n"
"\0";
const char *voronoidesign_source = "/* Gross Gloss by Team210 - 64k intro by Team210 at Solskogen 2k19\n"
"* Copyright (C) 2018  Alexander Kraus <nr4@z10.info>\n"
"*\n"
"* This program is free software: you can redistribute it and/or modify\n"
"* it under the terms of the GNU General Public License as published by\n"
"* the Free Software Foundation, either version 3 of the License, or\n"
"* (at your option) any later version.\n"
"*\n"
"* This program is distributed in the hope that it will be useful,\n"
"* but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"* GNU General Public License for more details.\n"
"*\n"
"* You should have received a copy of the GNU General Public License\n"
"* along with this program.  If not, see <https://www.gnu.org/licenses/>.\n"
"*/\n"
"\n"
"#version 130\n\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"// Global constants\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"float a = 1.0;\n"
"\n"
"float iScale;\n"
"\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void mfnoise(in vec2 x, in float d, in float b, in float e, out float n);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 z);\n"
"vec2 ind;\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    x.y += .3*iTime;\n"
"    \n"
"    float d, \n"
"        d2,\n"
"        dz,\n"
"        da,\n"
"        r;\n"
"    vec2 p, \n"
"        p2,\n"
"        y;\n"
"        \n"
"    // Net\n"
"    dvoronoi(6.*x.xy, d, p);\n"
"    dvoronoi(12.*x.xy, d2, p2);\n"
"    ind = p;\n"
"    \n"
"    x.z -= -.1+.4*p.x*p2.x/6./12.;\n"
"    \n"
"    // Displacement\n"
"    mfnoise(x.xy-iTime*c.yx, 2., 12., .25, dz);\n"
"    d = x.z-.1-d/12.+.1*dz-.2*d2/12.;\n"
"    //d = mix(d, length(x)-1., .01);\n"
"	sdf = vec2(d, 1.);\n"
"    \n"
"    // Discrete displacement\n"
"    mfnoise(p/6.-iTime*c.yx, 2., 12., .25, dz);\n"
"	add(sdf, vec2(length(x-vec3(p/6.,.14-.1*dz))-.02, 2.), sdf);\n"
"    \n"
"}   \n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"\n"
"float sm(float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void colorize(in vec2 x, out vec3 col)\n"
"{\n"
"    col = vec3(0.09,0.10,0.07);\n"
"    \n"
"    x.y += .3*iTime;\n"
"    \n"
"    float d, \n"
"        d2,\n"
"        dz,\n"
"        da,\n"
"        r;\n"
"    vec2 p, \n"
"        p2,\n"
"        y;\n"
"        \n"
"    // Net\n"
"    dvoronoi(6.*x.xy, d, p);\n"
"    dvoronoi(12.*x.xy, d2, p2);\n"
"    \n"
"    stroke(d, .02, d);\n"
"    col = mix(col, vec3(0.79,0.44,0.36), sm(d));\n"
"    \n"
"    stroke(d2, .02, d2);\n"
"    col = mix(col, vec3(0.89,0.44,0.26), sm(d2));\n"
"}\n"
"\n"
"void mainImage( out vec4 fragColor, in vec2 fragCoord )\n"
"{\n"
"    a = iResolution.x/iResolution.y;\n"
"    \n"
"    iScale = fract(iTime);\n"
"    \n"
"    vec2 uv = fragCoord/iResolution.yy-0.5*vec2(a, 1.0), \n"
"        s;\n"
"    vec3 col = c.yyy, \n"
"        o = c.yzx,\n"
"        r = c.xyy, \n"
"        u = normalize(c.yxx),\n"
"        t = c.yyy, \n"
"        dir,\n"
"        n,\n"
"        x;\n"
"    int N = 200,\n"
"        i;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = normalize(t-o);\n"
"\n"
"    float d = -(o.z-.2)/dir.z;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-4)break;\n"
"        if(x.z<-.1)\n"
"        {\n"
"            col = .2*c.xxx;\n"
"            i = N;\n"
"            break;\n"
"        }\n"
"        d += min(s.x,3.e-3);\n"
"        //d += s.x;\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        normal(x,n,1.e-3);\n"
"        \n"
"        if(s.y == 1.)\n"
"        {\n"
"            vec3 l = normalize(x+.5*c.yzx);\n"
"            colorize(x.xy, col);\n"
"            col = .1*col\n"
"                + 1.8*col * abs(dot(l,n))\n"
"                + 2.5 * col * abs(pow(dot(reflect(x-l,n),dir),2.));\n"
"        }\n"
"        else if(s.y == 2.)\n"
"        {\n"
"            vec3 l = normalize(x+c.xzx);\n"
"            float r;\n"
"            rand(ind, r);\n"
"            col = mix(vec3(0.99,0.43,0.15),vec3(0.44,0.07,0.66),iScale*r);\n"
"            col = .1*col\n"
"                + .8*col * abs(dot(l,n))\n"
"                + 6.5*col * abs(pow(dot(reflect(x-l,n),dir),3.));\n"
"        }\n"
"    }\n"
"    \n"
"    //col += col;\n"
"    \n"
"    col *= col;\n"
"    col = mix(col, c.yyy, clamp((d-2.-(o.z-.2)/dir.z)/4.,0.,1.));\n"
"    fragColor = vec4(clamp(col,0.,1.),1.0);\n"
"}	\n"
"\n"
"void main()\n"
"{\n"
"    mainImage(gl_FragColor, gl_FragCoord.xy);\n"
"}\n"
"\0";
const char *groundboxes_source = "/* Gross Gloss by Team210 - 64k intro by Team210 at Solskogen 2k19\n"
"* Copyright (C) 2018  Alexander Kraus <nr4@z10.info>\n"
"*\n"
"* This program is free software: you can redistribute it and/or modify\n"
"* it under the terms of the GNU General Public License as published by\n"
"* the Free Software Foundation, either version 3 of the License, or\n"
"* (at your option) any later version.\n"
"*\n"
"* This program is distributed in the hope that it will be useful,\n"
"* but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"* GNU General Public License for more details.\n"
"*\n"
"* You should have received a copy of the GNU General Public License\n"
"* along with this program.  If not, see <https://www.gnu.org/licenses/>.\n"
"*/\n"
"\n"
"#version 130\n\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"out vec4 gl_FragColor;\n"
"\n"
"// Global constants\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"float a = 1.0;\n"
"\n"
"float iScale;\n"
"\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void rot3(in vec3 p, out mat3 rot);\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void dlinesegment3(in vec3 x, in vec3 p1, in vec3 p2, out float d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void zextrude(in float z, in float d2d, in float h, out float d);\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"\n"
"vec2 ind;\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    x.y += .3*iTime;\n"
"    mat2 R = mat2(cos(pi/4.), sin(pi/4.), -sin(pi/4.), cos(pi/4.));\n"
"    x.xy = R*x.xy;\n"
"    \n"
"    float d,\n"
"        size = .1;\n"
"    vec2 x2 = mod(x.xy,size)-.5*size;\n"
"	\n"
"    ind = (x.xy - x2)/size;\n"
"    dbox(x2, .5*size*c.xx, d);\n"
"    zextrude(x.z, -d-.005, .05, d);\n"
"    d = max(x.z,d);\n"
"    d = abs(d);\n"
"    sdf = vec2(d,2.);\n"
"    \n"
"    float r;\n"
"    rand(1.e0*ind-1.e2*floor(iTime), r);\n"
"    //lfnoise(12.*ind-1.*iTime, r);\n"
"    //r = .5+.5*r;\n"
"    if(r > .7)\n"
"    {\n"
"        float r2;\n"
"        rand(ind-1337., r2);\n"
"        r2 = 1.;\n"
"        dbox(x2, .5*size*c.xx, d);\n"
"        zextrude(x.z, -d-.02, .3*(r-.7)/.3*r2, d);\n"
"        stroke(d, .001, d);\n"
"        add(sdf, vec2(d,1.), sdf);\n"
"    }\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"float sm(float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void colorize(in vec2 x, out vec3 col)\n"
"{\n"
"    x.y += .3*iTime;\n"
"    mat2 R = mat2(cos(pi/4.), sin(pi/4.), -sin(pi/4.), cos(pi/4.));\n"
"    x.xy = R*x.xy;\n"
"    \n"
"    float d,\n"
"        size = .1,\n"
"        r;\n"
"    vec2 x2 = mod(x.xy,size)-.5*size;\n"
"    \n"
"    rand(1.e0*ind-1.e2*floor(iTime), r);\n"
"    //lfnoise(12.*ind-1.*iTime, r);\n"
"    //r = .5+.5*r;\n"
"    col = mix(.14*c.xxx, .33*c.xxx, r);\n"
"    dbox(x2, .35*size*c.xx, d);\n"
"    if(r > .9)\n"
"    {\n"
"        col = mix(col, mix(c.xxy, c.xxx, .8), sm(d));\n"
"        stroke(d, .0025, d);\n"
"        col = mix(col, mix(c.xyy,c.xxx,.8), sm(d));\n"
"        stroke(d-.004, .002, d);\n"
"        col = mix(col, c.xyy, sm(d));\n"
"    }\n"
"	else if(r > .8)\n"
"    {\n"
"        col = mix(col, mix(c.xyy, c.xxx, .8), sm(d));\n"
"        stroke(d, .0025, d);\n"
"        col = mix(col, mix(.7*c.xxy,c.xxx,.8), sm(d));\n"
"        stroke(d-.004, .002, d);\n"
"        col = mix(col, .7*c.xxy, sm(d));\n"
"    }\n"
"    else if(r > .7)\n"
"    {\n"
"        col = mix(col, mix(c.xyy, c.xxx, .8), sm(d));\n"
"        stroke(d, .0025, d);\n"
"        col = mix(col, mix(mix(c.xxy, c.xyy, .5),c.xxx,.8), sm(d));\n"
"        stroke(d-.004, .002, d);\n"
"        col = mix(col, mix(c.xxy, c.xyy, .5), sm(d));\n"
"    }\n"
"    \n"
"    // Truchet\n"
"    /*\n"
"    float da = floor(4.*r)*pi/2.;\n"
"    R = mat2(cos(da), sin(da),-sin(da),cos(da));\n"
"    x2 = R * x2;\n"
"    if(r > .3)\n"
"    {\n"
"    	dspline2(x2,-.5*size*c.xy, c.yy, -.5*size*c.yx, d);\n"
"        dspline2(x2,.5*size*c.xy, c.yy, .5*size*c.yx, da);\n"
"        \n"
"    }\n"
"    else\n"
"    {\n"
"        dlinesegment(x2,-.5*size*c.xy, .5*size*c.xy, d);\n"
"        dlinesegment(x2,-.5*size*c.yx, .5*size*c.yx, da);\n"
"    }\n"
"    d = min(d, da);\n"
"    stroke(d, .001, d);\n"
"    col = mix(col,  .9*c.xyy, sm(d));\n"
"    stroke(d-.004, .002, d);\n"
"    col = mix(col, .0*c.xyy, sm(d));\n"
"*/\n"
"}\n"
"\n"
"void mainImage( out vec4 fragColor, in vec2 fragCoord )\n"
"{\n"
"    a = iResolution.x/iResolution.y;\n"
"    \n"
"    iScale = fract(iTime);\n"
"    \n"
"    vec2 uv = fragCoord/iResolution.yy-0.5*vec2(a, 1.0), \n"
"        s;\n"
"    vec3 col = c.yyy, \n"
"        o = c.yzx,\n"
"        r = c.xyy, \n"
"        u = normalize(c.yxx), \n"
"        t = c.yyy, \n"
"        dir,\n"
"        n,\n"
"        x;\n"
"    int N = 100,\n"
"        i;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = normalize(t-o);\n"
"\n"
"    float d = -(o.z-.15)/dir.z;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-4)break;\n"
"        if(x.z<-.05)\n"
"        {\n"
"            col = .2*c.xxx;\n"
"            i = N;\n"
"            break;\n"
"        }\n"
"        d += min(s.x,5.e-3);\n"
"        //d += s.x;\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        normal(x,n, 5.e-4);\n"
"        \n"
"        if(s.y == 1.)\n"
"        {\n"
"            vec3 l = normalize(x+c.xzx);\n"
"            vec3 c1;\n"
"            \n"
"            float r;\n"
"		    rand(ind-1.e2*floor(iTime), r);\n"
"            if(r > .9)\n"
"                col = c.xyy;\n"
"            else if(r > .8)\n"
"                col = .7*c.xxy;\n"
"            else if(r > .7)\n"
"                col = mix(c.xxy, c.xyy, .5);\n"
"            float sc = clamp((r-.7)/.3,0.,1.);\n"
"            col = mix(mix(col, c.xxx, .1*sc), .4*c.xyy, sc);\n"
"            col = .3*col\n"
"                + .9*col * abs(dot(l,n))\n"
"                + 1.3*col * abs(pow(dot(reflect(-l,n),dir),3.));\n"
"            col = mix(col, c.xxx, .4);\n"
"            col *= col;\n"
"            \n"
"            d = -(o.z)/dir.z;\n"
"            x = o + d * dir;\n"
"            scene(x,s);\n"
"            l = normalize(x+c.xzx);\n"
"            colorize(x.xy, c1);\n"
"            n = c.yyx;\n"
"            \n"
"            c1 = .1*c1\n"
"                + .8*c1 * abs(dot(l,n))\n"
"                + c1 * abs(pow(dot(reflect(-l,n),dir),3.));\n"
"            col = mix(col, c1, .3);\n"
"        }\n"
"        else if(s.y == 2.)\n"
"        {\n"
"            vec3 l = normalize(x+c.xzx);\n"
"            float r;\n"
"            \n"
"            colorize(x.xy, col);\n"
"            col = .1*col\n"
"                + .8*col * abs(dot(l,n))\n"
"                + col * abs(pow(dot(reflect(-l,n),dir),3.));\n"
"        }\n"
"    }\n"
"    col += col;\n"
"    col *= col;\n"
"    \n"
"    fragColor = vec4(clamp(col,0.,1.),1.0);\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    mainImage(gl_FragColor, gl_FragCoord.xy);\n"
"}\n"
"\0";
void Loadrand()
{
    int rand_size = strlen(rand_source);
    rand_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(rand_handle, 1, (GLchar **)&rand_source, &rand_size);
    glCompileShader(rand_handle);
#ifdef DEBUG
    printf("---> rand Shader:\n");
    debug(rand_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadlfnoise()
{
    int lfnoise_size = strlen(lfnoise_source);
    lfnoise_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(lfnoise_handle, 1, (GLchar **)&lfnoise_source, &lfnoise_size);
    glCompileShader(lfnoise_handle);
#ifdef DEBUG
    printf("---> lfnoise Shader:\n");
    debug(lfnoise_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadmfnoise()
{
    int mfnoise_size = strlen(mfnoise_source);
    mfnoise_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(mfnoise_handle, 1, (GLchar **)&mfnoise_source, &mfnoise_size);
    glCompileShader(mfnoise_handle);
#ifdef DEBUG
    printf("---> mfnoise Shader:\n");
    debug(mfnoise_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadstroke()
{
    int stroke_size = strlen(stroke_source);
    stroke_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(stroke_handle, 1, (GLchar **)&stroke_source, &stroke_size);
    glCompileShader(stroke_handle);
#ifdef DEBUG
    printf("---> stroke Shader:\n");
    debug(stroke_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadadd()
{
    int add_size = strlen(add_source);
    add_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(add_handle, 1, (GLchar **)&add_source, &add_size);
    glCompileShader(add_handle);
#ifdef DEBUG
    printf("---> add Shader:\n");
    debug(add_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddvoronoi()
{
    int dvoronoi_size = strlen(dvoronoi_source);
    dvoronoi_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dvoronoi_handle, 1, (GLchar **)&dvoronoi_source, &dvoronoi_size);
    glCompileShader(dvoronoi_handle);
#ifdef DEBUG
    printf("---> dvoronoi Shader:\n");
    debug(dvoronoi_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadnormal()
{
    int normal_size = strlen(normal_source);
    normal_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(normal_handle, 1, (GLchar **)&normal_source, &normal_size);
    glCompileShader(normal_handle);
#ifdef DEBUG
    printf("---> normal Shader:\n");
    debug(normal_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadrot3()
{
    int rot3_size = strlen(rot3_source);
    rot3_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(rot3_handle, 1, (GLchar **)&rot3_source, &rot3_size);
    glCompileShader(rot3_handle);
#ifdef DEBUG
    printf("---> rot3 Shader:\n");
    debug(rot3_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddbox()
{
    int dbox_size = strlen(dbox_source);
    dbox_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dbox_handle, 1, (GLchar **)&dbox_source, &dbox_size);
    glCompileShader(dbox_handle);
#ifdef DEBUG
    printf("---> dbox Shader:\n");
    debug(dbox_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddlinesegment3()
{
    int dlinesegment3_size = strlen(dlinesegment3_source);
    dlinesegment3_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dlinesegment3_handle, 1, (GLchar **)&dlinesegment3_source, &dlinesegment3_size);
    glCompileShader(dlinesegment3_handle);
#ifdef DEBUG
    printf("---> dlinesegment3 Shader:\n");
    debug(dlinesegment3_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadzextrude()
{
    int zextrude_size = strlen(zextrude_source);
    zextrude_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(zextrude_handle, 1, (GLchar **)&zextrude_source, &zextrude_size);
    glCompileShader(zextrude_handle);
#ifdef DEBUG
    printf("---> zextrude Shader:\n");
    debug(zextrude_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}

void LoadSymbols()
{
    Loadrand();
    updateBar();
    Loadlfnoise();
    updateBar();
    Loadmfnoise();
    updateBar();
    Loadstroke();
    updateBar();
    Loadadd();
    updateBar();
    Loaddvoronoi();
    updateBar();
    Loadnormal();
    updateBar();
    Loadrot3();
    updateBar();
    Loaddbox();
    updateBar();
    Loaddlinesegment3();
    updateBar();
    Loadzextrude();
    updateBar();
}
int voronoidesign_program, voronoidesign_handle, groundboxes_program, groundboxes_handle;
int voronoidesign_iTime_location;
voronoidesign_iResolution_location;
int groundboxes_iTime_location;
groundboxes_iResolution_location;
const int nprograms = 2;

void Loadvoronoidesign()
{
    int voronoidesign_size = strlen(voronoidesign_source);
    voronoidesign_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(voronoidesign_handle, 1, (GLchar **)&voronoidesign_source, &voronoidesign_size);
    glCompileShader(voronoidesign_handle);
#ifdef DEBUG
    printf("---> voronoidesign Shader:\n");
    debug(voronoidesign_handle);
    printf(">>>>\n");
#endif
    voronoidesign_program = glCreateProgram();
    glAttachShader(voronoidesign_program,voronoidesign_handle);
    glAttachShader(voronoidesign_program,rand_handle);
    glAttachShader(voronoidesign_program,lfnoise_handle);
    glAttachShader(voronoidesign_program,mfnoise_handle);
    glAttachShader(voronoidesign_program,stroke_handle);
    glAttachShader(voronoidesign_program,add_handle);
    glAttachShader(voronoidesign_program,dvoronoi_handle);
    glAttachShader(voronoidesign_program,normal_handle);
    glLinkProgram(voronoidesign_program);
#ifdef DEBUG
    printf("---> voronoidesign Program:\n");
    debugp(voronoidesign_program);
    printf(">>>>\n");
#endif
    glUseProgram(voronoidesign_program);
    voronoidesign_iTime_location = glGetUniformLocation(voronoidesign_program, "iTime");
    voronoidesign_iResolution_location = glGetUniformLocation(voronoidesign_program, "iResolution");
    progress += .2/(float)nprograms;
}

void Loadgroundboxes()
{
    int groundboxes_size = strlen(groundboxes_source);
    groundboxes_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(groundboxes_handle, 1, (GLchar **)&groundboxes_source, &groundboxes_size);
    glCompileShader(groundboxes_handle);
#ifdef DEBUG
    printf("---> groundboxes Shader:\n");
    debug(groundboxes_handle);
    printf(">>>>\n");
#endif
    groundboxes_program = glCreateProgram();
    glAttachShader(groundboxes_program,groundboxes_handle);
    glAttachShader(groundboxes_program,rand_handle);
    glAttachShader(groundboxes_program,lfnoise_handle);
    glAttachShader(groundboxes_program,rot3_handle);
    glAttachShader(groundboxes_program,dbox_handle);
    glAttachShader(groundboxes_program,dlinesegment3_handle);
    glAttachShader(groundboxes_program,stroke_handle);
    glAttachShader(groundboxes_program,zextrude_handle);
    glAttachShader(groundboxes_program,add_handle);
    glAttachShader(groundboxes_program,normal_handle);
    glLinkProgram(groundboxes_program);
#ifdef DEBUG
    printf("---> groundboxes Program:\n");
    debugp(groundboxes_program);
    printf(">>>>\n");
#endif
    glUseProgram(groundboxes_program);
    groundboxes_iTime_location = glGetUniformLocation(groundboxes_program, "iTime");
    groundboxes_iResolution_location = glGetUniformLocation(groundboxes_program, "iResolution");
    progress += .2/(float)nprograms;
}

void LoadPrograms()
{
    Loadvoronoidesign();
    updateBar();
    Loadgroundboxes();
    updateBar();
}
#endif
