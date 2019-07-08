/* Gross Gloss by Team210 - 64k intro by Team210 at Solskogen 2k19
* Copyright (C) 2018  Alexander Kraus <nr4@z10.info>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#version 130

uniform float iTime;
uniform vec2 iResolution;

// Global constants
const float pi = acos(-1.);
const vec3 c = vec3(1.0, 0.0, -1.0);
float a = 1.0;

float iScale;

void rand(in vec2 x, out float n);
void lfnoise(in vec2 t, out float n);
void mfnoise(in vec2 x, in float d, in float b, in float e, out float n);
void stroke(in float d0, in float s, out float d);
void add(in vec2 sda, in vec2 sdb, out vec2 sdf);
void dvoronoi(in vec2 x, out float d, out vec2 z);
vec2 ind;
void scene(in vec3 x, out vec2 sdf)
{
    x.y += .3*iTime;
    
    float d, 
        d2,
        dz,
        da,
        r;
    vec2 p, 
        p2,
        y;
        
    // Net
    dvoronoi(6.*x.xy, d, p);
    dvoronoi(12.*x.xy, d2, p2);
    ind = p;
    
    x.z -= -.1+.4*p.x*p2.x/6./12.;
    
    // Displacement
    mfnoise(x.xy-iTime*c.yx, 2., 12., .25, dz);
    d = x.z-.1-d/12.+.1*dz-.2*d2/12.;
    //d = mix(d, length(x)-1., .01);
	sdf = vec2(d, 1.);
    
    // Discrete displacement
    mfnoise(p/6.-iTime*c.yx, 2., 12., .25, dz);
	add(sdf, vec2(length(x-vec3(p/6.,.14-.1*dz))-.02, 2.), sdf);
    
}   

void normal(in vec3 x, out vec3 n, in float dx);

float sm(float d)
{
    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);
}

void colorize(in vec2 x, out vec3 col)
{
    col = vec3(0.09,0.10,0.07);
    
    x.y += .3*iTime;
    
    float d, 
        d2,
        dz,
        da,
        r;
    vec2 p, 
        p2,
        y;
        
    // Net
    dvoronoi(6.*x.xy, d, p);
    dvoronoi(12.*x.xy, d2, p2);
    
    stroke(d, .02, d);
    col = mix(col, vec3(0.79,0.44,0.36), sm(d));
    
    stroke(d2, .02, d2);
    col = mix(col, vec3(0.89,0.44,0.26), sm(d2));
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    a = iResolution.x/iResolution.y;
    
    iScale = fract(iTime);
    
    vec2 uv = fragCoord/iResolution.yy-0.5*vec2(a, 1.0), 
        s;
    vec3 col = c.yyy, 
        o = c.yzx,
        r = c.xyy, 
        u = normalize(c.yxx),
        t = c.yyy, 
        dir,
        n,
        x;
    int N = 200,
        i;
    t = uv.x * r + uv.y * u;
    dir = normalize(t-o);

    float d = -(o.z-.2)/dir.z;
    
    for(i = 0; i<N; ++i)
    {
     	x = o + d * dir;
        scene(x,s);
        if(s.x < 1.e-4)break;
        if(x.z<-.1)
        {
            col = .2*c.xxx;
            i = N;
            break;
        }
        d += min(s.x,3.e-3);
        //d += s.x;
    }
    
    if(i < N)
    {
        normal(x,n,1.e-3);
        
        if(s.y == 1.)
        {
            vec3 l = normalize(x+.5*c.yzx);
            colorize(x.xy, col);
            col = .1*col
                + 1.8*col * abs(dot(l,n))
                + 2.5 * col * abs(pow(dot(reflect(x-l,n),dir),2.));
        }
        else if(s.y == 2.)
        {
            vec3 l = normalize(x+c.xzx);
            float r;
            rand(ind, r);
            col = mix(vec3(0.99,0.43,0.15),vec3(0.44,0.07,0.66),iScale*r);
            col = .1*col
                + .8*col * abs(dot(l,n))
                + 6.5*col * abs(pow(dot(reflect(x-l,n),dir),3.));
        }
    }
    
    //col += col;
    
    col *= col;
    col = mix(col, c.yyy, clamp((d-2.-(o.z-.2)/dir.z)/4.,0.,1.));
    fragColor = vec4(clamp(col,0.,1.),1.0);
}	

void main()
{
    mainImage(gl_FragColor, gl_FragCoord.xy);
}
