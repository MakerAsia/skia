
out vec4 sk_FragColor;
float fn(float v) {
    switch (int(v)) {
        case 1:
            return 2.0;
        default:
            return 3.0;
    }
}
layout (set = 0) uniform vec3 colRGB;
void main() {
    float v = sqrt(1.0);
    sk_FragColor = vec4(v);
    sk_FragColor = vec4(vec3(v), 0.0).wzyx;
    sk_FragColor = vec3(vec2(v), 0.0).zzxy;
    sk_FragColor = vec3(vec3(vec2(v), 0.0).yx, 1.0).zzxy;
    sk_FragColor = vec3(vec2(v), 1.0).xyzz;
    sk_FragColor = vec4(v);
    sk_FragColor = vec4(vec2(v), 1.0, 1.0);
    sk_FragColor = vec4(v);
    sk_FragColor = vec3(fn(v), 123.0, 456.0).yyzz;
    sk_FragColor = vec3(fn(v), vec2(123.0, 456.0)).yyzz;
    sk_FragColor = vec4(123.0, 456.0, 456.0, fn(v));
    sk_FragColor = vec4(123.0, 456.0, 456.0, fn(v));
    sk_FragColor = vec3(fn(v), 123.0, 456.0).yxxz;
    sk_FragColor = vec3(fn(v), vec2(123.0, 456.0)).yxxz;
    sk_FragColor = vec4(1.0, 1.0, 2.0, 3.0);
    sk_FragColor = vec4(colRGB.x, colRGB.y, colRGB.z, 1.0);
    sk_FragColor = vec4(colRGB.x, 1.0, colRGB.y, colRGB.z);
    sk_FragColor.xyzw = sk_FragColor;
    sk_FragColor.wzyx = sk_FragColor;
    sk_FragColor.xyzw.xw = sk_FragColor.yz;
    sk_FragColor.wzyx.yzw = vec3(sk_FragColor.ww, 1.0);
}
