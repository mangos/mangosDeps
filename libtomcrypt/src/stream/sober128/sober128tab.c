/* LibTomCrypt, modular cryptographic library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/**
   @file sober128tab.c
   SOBER-128 Tables
*/

#ifdef LTC_SOBER128TAB_C

/* $ID$ */
/* @(#)TuringMultab.h   1.3 (QUALCOMM) 02/09/03 */
/* Multiplication table for Turing using 0xD02B4367 */
static const ulong32 Multab[256] = {
    0x00000000, 0xD02B4367, 0xED5686CE, 0x3D7DC5A9,
    0x97AC41D1, 0x478702B6, 0x7AFAC71F, 0xAAD18478,
    0x631582EF, 0xB33EC188, 0x8E430421, 0x5E684746,
    0xF4B9C33E, 0x24928059, 0x19EF45F0, 0xC9C40697,
    0xC62A4993, 0x16010AF4, 0x2B7CCF5D, 0xFB578C3A,
    0x51860842, 0x81AD4B25, 0xBCD08E8C, 0x6CFBCDEB,
    0xA53FCB7C, 0x7514881B, 0x48694DB2, 0x98420ED5,
    0x32938AAD, 0xE2B8C9CA, 0xDFC50C63, 0x0FEE4F04,
    0xC154926B, 0x117FD10C, 0x2C0214A5, 0xFC2957C2,
    0x56F8D3BA, 0x86D390DD, 0xBBAE5574, 0x6B851613,
    0xA2411084, 0x726A53E3, 0x4F17964A, 0x9F3CD52D,
    0x35ED5155, 0xE5C61232, 0xD8BBD79B, 0x089094FC,
    0x077EDBF8, 0xD755989F, 0xEA285D36, 0x3A031E51,
    0x90D29A29, 0x40F9D94E, 0x7D841CE7, 0xADAF5F80,
    0x646B5917, 0xB4401A70, 0x893DDFD9, 0x59169CBE,
    0xF3C718C6, 0x23EC5BA1, 0x1E919E08, 0xCEBADD6F,
    0xCFA869D6, 0x1F832AB1, 0x22FEEF18, 0xF2D5AC7F,
    0x58042807, 0x882F6B60, 0xB552AEC9, 0x6579EDAE,
    0xACBDEB39, 0x7C96A85E, 0x41EB6DF7, 0x91C02E90,
    0x3B11AAE8, 0xEB3AE98F, 0xD6472C26, 0x066C6F41,
    0x09822045, 0xD9A96322, 0xE4D4A68B, 0x34FFE5EC,
    0x9E2E6194, 0x4E0522F3, 0x7378E75A, 0xA353A43D,
    0x6A97A2AA, 0xBABCE1CD, 0x87C12464, 0x57EA6703,
    0xFD3BE37B, 0x2D10A01C, 0x106D65B5, 0xC04626D2,
    0x0EFCFBBD, 0xDED7B8DA, 0xE3AA7D73, 0x33813E14,
    0x9950BA6C, 0x497BF90B, 0x74063CA2, 0xA42D7FC5,
    0x6DE97952, 0xBDC23A35, 0x80BFFF9C, 0x5094BCFB,
    0xFA453883, 0x2A6E7BE4, 0x1713BE4D, 0xC738FD2A,
    0xC8D6B22E, 0x18FDF149, 0x258034E0, 0xF5AB7787,
    0x5F7AF3FF, 0x8F51B098, 0xB22C7531, 0x62073656,
    0xABC330C1, 0x7BE873A6, 0x4695B60F, 0x96BEF568,
    0x3C6F7110, 0xEC443277, 0xD139F7DE, 0x0112B4B9,
    0xD31DD2E1, 0x03369186, 0x3E4B542F, 0xEE601748,
    0x44B19330, 0x949AD057, 0xA9E715FE, 0x79CC5699,
    0xB008500E, 0x60231369, 0x5D5ED6C0, 0x8D7595A7,
    0x27A411DF, 0xF78F52B8, 0xCAF29711, 0x1AD9D476,
    0x15379B72, 0xC51CD815, 0xF8611DBC, 0x284A5EDB,
    0x829BDAA3, 0x52B099C4, 0x6FCD5C6D, 0xBFE61F0A,
    0x7622199D, 0xA6095AFA, 0x9B749F53, 0x4B5FDC34,
    0xE18E584C, 0x31A51B2B, 0x0CD8DE82, 0xDCF39DE5,
    0x1249408A, 0xC26203ED, 0xFF1FC644, 0x2F348523,
    0x85E5015B, 0x55CE423C, 0x68B38795, 0xB898C4F2,
    0x715CC265, 0xA1778102, 0x9C0A44AB, 0x4C2107CC,
    0xE6F083B4, 0x36DBC0D3, 0x0BA6057A, 0xDB8D461D,
    0xD4630919, 0x04484A7E, 0x39358FD7, 0xE91ECCB0,
    0x43CF48C8, 0x93E40BAF, 0xAE99CE06, 0x7EB28D61,
    0xB7768BF6, 0x675DC891, 0x5A200D38, 0x8A0B4E5F,
    0x20DACA27, 0xF0F18940, 0xCD8C4CE9, 0x1DA70F8E,
    0x1CB5BB37, 0xCC9EF850, 0xF1E33DF9, 0x21C87E9E,
    0x8B19FAE6, 0x5B32B981, 0x664F7C28, 0xB6643F4F,
    0x7FA039D8, 0xAF8B7ABF, 0x92F6BF16, 0x42DDFC71,
    0xE80C7809, 0x38273B6E, 0x055AFEC7, 0xD571BDA0,
    0xDA9FF2A4, 0x0AB4B1C3, 0x37C9746A, 0xE7E2370D,
    0x4D33B375, 0x9D18F012, 0xA06535BB, 0x704E76DC,
    0xB98A704B, 0x69A1332C, 0x54DCF685, 0x84F7B5E2,
    0x2E26319A, 0xFE0D72FD, 0xC370B754, 0x135BF433,
    0xDDE1295C, 0x0DCA6A3B, 0x30B7AF92, 0xE09CECF5,
    0x4A4D688D, 0x9A662BEA, 0xA71BEE43, 0x7730AD24,
    0xBEF4ABB3, 0x6EDFE8D4, 0x53A22D7D, 0x83896E1A,
    0x2958EA62, 0xF973A905, 0xC40E6CAC, 0x14252FCB,
    0x1BCB60CF, 0xCBE023A8, 0xF69DE601, 0x26B6A566,
    0x8C67211E, 0x5C4C6279, 0x6131A7D0, 0xB11AE4B7,
    0x78DEE220, 0xA8F5A147, 0x958864EE, 0x45A32789,
    0xEF72A3F1, 0x3F59E096, 0x0224253F, 0xD20F6658,
};

/* $ID$ */
/* Sbox for SOBER-128 */
/*
 * This is really the combination of two SBoxes; the least significant
 * 24 bits comes from:
 * 8->32 Sbox generated by Millan et. al. at Queensland University of
 * Technology. See: E. Dawson, W. Millan, L. Burnett, G. Carter,
 * "On the Design of 8*32 S-boxes". Unpublished report, by the
 * Information Systems Research Centre,
 * Queensland University of Technology, 1999.
 *
 * The most significant 8 bits are the Skipjack "F table", which can be
 * found at http://csrc.nist.gov/CryptoToolkit/skipjack/skipjack.pdf .
 * In this optimised table, though, the intent is to XOR the word from
 * the table selected by the high byte with the input word. Thus, the
 * high byte is actually the Skipjack F-table entry XORED with its
 * table index.
 */
static const ulong32 Sbox[256] = {
    0xa3aa1887, 0xd65e435c, 0x0b65c042, 0x800e6ef4,
    0xfc57ee20, 0x4d84fed3, 0xf066c502, 0xf354e8ae,
    0xbb2ee9d9, 0x281f38d4, 0x1f829b5d, 0x735cdf3c,
    0x95864249, 0xbc2e3963, 0xa1f4429f, 0xf6432c35,
    0xf7f40325, 0x3cc0dd70, 0x5f973ded, 0x9902dc5e,
    0xda175b42, 0x590012bf, 0xdc94d78c, 0x39aab26b,
    0x4ac11b9a, 0x8c168146, 0xc3ea8ec5, 0x058ac28f,
    0x52ed5c0f, 0x25b4101c, 0x5a2db082, 0x370929e1,
    0x2a1843de, 0xfe8299fc, 0x202fbc4b, 0x833915dd,
    0x33a803fa, 0xd446b2de, 0x46233342, 0x4fcee7c3,
    0x3ad607ef, 0x9e97ebab, 0x507f859b, 0xe81f2e2f,
    0xc55b71da, 0xd7e2269a, 0x1339c3d1, 0x7ca56b36,
    0xa6c9def2, 0xb5c9fc5f, 0x5927b3a3, 0x89a56ddf,
    0xc625b510, 0x560f85a7, 0xace82e71, 0x2ecb8816,
    0x44951e2a, 0x97f5f6af, 0xdfcbc2b3, 0xce4ff55d,
    0xcb6b6214, 0x2b0b83e3, 0x549ea6f5, 0x9de041af,
    0x792f1f17, 0xf73b99ee, 0x39a65ec0, 0x4c7016c6,
    0x857709a4, 0xd6326e01, 0xc7b280d9, 0x5cfb1418,
    0xa6aff227, 0xfd548203, 0x506b9d96, 0xa117a8c0,
    0x9cd5bf6e, 0xdcee7888, 0x61fcfe64, 0xf7a193cd,
    0x050d0184, 0xe8ae4930, 0x88014f36, 0xd6a87088,
    0x6bad6c2a, 0x1422c678, 0xe9204de7, 0xb7c2e759,
    0x0200248e, 0x013b446b, 0xda0d9fc2, 0x0414a895,
    0x3a6cc3a1, 0x56fef170, 0x86c19155, 0xcf7b8a66,
    0x551b5e69, 0xb4a8623e, 0xa2bdfa35, 0xc4f068cc,
    0x573a6acd, 0x6355e936, 0x03602db9, 0x0edf13c1,
    0x2d0bb16d, 0x6980b83c, 0xfeb23763, 0x3dd8a911,
    0x01b6bc13, 0xf55579d7, 0xf55c2fa8, 0x19f4196e,
    0xe7db5476, 0x8d64a866, 0xc06e16ad, 0xb17fc515,
    0xc46feb3c, 0x8bc8a306, 0xad6799d9, 0x571a9133,
    0x992466dd, 0x92eb5dcd, 0xac118f50, 0x9fafb226,
    0xa1b9cef3, 0x3ab36189, 0x347a19b1, 0x62c73084,
    0xc27ded5c, 0x6c8bc58f, 0x1cdde421, 0xed1e47fb,
    0xcdcc715e, 0xb9c0ff99, 0x4b122f0f, 0xc4d25184,
    0xaf7a5e6c, 0x5bbf18bc, 0x8dd7c6e0, 0x5fb7e420,
    0x521f523f, 0x4ad9b8a2, 0xe9da1a6b, 0x97888c02,
    0x19d1e354, 0x5aba7d79, 0xa2cc7753, 0x8c2d9655,
    0x19829da1, 0x531590a7, 0x19c1c149, 0x3d537f1c,
    0x50779b69, 0xed71f2b7, 0x463c58fa, 0x52dc4418,
    0xc18c8c76, 0xc120d9f0, 0xafa80d4d, 0x3b74c473,
    0xd09410e9, 0x290e4211, 0xc3c8082b, 0x8f6b334a,
    0x3bf68ed2, 0xa843cc1b, 0x8d3c0ff3, 0x20e564a0,
    0xf8f55a4f, 0x2b40f8e7, 0xfea7f15f, 0xcf00fe21,
    0x8a6d37d6, 0xd0d506f1, 0xade00973, 0xefbbde36,
    0x84670fa8, 0xfa31ab9e, 0xaedab618, 0xc01f52f5,
    0x6558eb4f, 0x71b9e343, 0x4b8d77dd, 0x8cb93da6,
    0x740fd52d, 0x425412f8, 0xc5a63360, 0x10e53ad0,
    0x5a700f1c, 0x8324ed0b, 0xe53dc1ec, 0x1a366795,
    0x6d549d15, 0xc5ce46d7, 0xe17abe76, 0x5f48e0a0,
    0xd0f07c02, 0x941249b7, 0xe49ed6ba, 0x37a47f78,
    0xe1cfffbd, 0xb007ca84, 0xbb65f4da, 0xb59f35da,
    0x33d2aa44, 0x417452ac, 0xc0d674a7, 0x2d61a46a,
    0xdc63152a, 0x3e12b7aa, 0x6e615927, 0xa14fb118,
    0xa151758d, 0xba81687b, 0xe152f0b3, 0x764254ed,
    0x34c77271, 0x0a31acab, 0x54f94aec, 0xb9e994cd,
    0x574d9e81, 0x5b623730, 0xce8a21e8, 0x37917f0b,
    0xe8a9b5d6, 0x9697adf8, 0xf3d30431, 0x5dcac921,
    0x76b35d46, 0xaa430a36, 0xc2194022, 0x22bca65e,
    0xdaec70ba, 0xdfaea8cc, 0x777bae8b, 0x242924d5,
    0x1f098a5a, 0x4b396b81, 0x55de2522, 0x435c1cb8,
    0xaeb8fe1d, 0x9db3c697, 0x5b164f83, 0xe0c16376,
    0xa319224c, 0xd0203b35, 0x433ac0fe, 0x1466a19a,
    0x45f0b24f, 0x51fda998, 0xc0d52d71, 0xfa0896a8,
    0xf9e6053f, 0xa4b0d300, 0xd499cbcc, 0xb95e3d40,
};

#endif /* LTC_SOBER128TAB_C */
