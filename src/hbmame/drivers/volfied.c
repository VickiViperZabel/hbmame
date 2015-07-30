// license:BSD-3-Clause
// copyright-holders:Robbbert
#include "../mame/drivers/volfied.c"

ROM_START( volfiedg )
	ROM_REGION( 0x100000, "maincpu", 0 )     /* 68000 code and tile data */
	ROM_LOAD16_BYTE( "c04-12-1.30g", 0x00000, 0x10000, CRC(f13c5621) SHA1(b50aaadb1a3128aa5ecbab2a1450c5e817f33620) )
	ROM_LOAD16_BYTE( "c04-08-1.10g", 0x00001, 0x10000, CRC(b7e5472e) SHA1(68323e46ffee7cf8d2119405543353691673ac05) )
	ROM_LOAD16_BYTE( "c04-11-1.29g", 0x20000, 0x10000, CRC(54730fe3) SHA1(796693cd2cfb539f6691aa4e359c47cfd7348734) )
	ROM_LOAD16_BYTE( "c04-25-1.9g",  0x20001, 0x10000, CRC(cff7aee1) SHA1(1d9a3ddebafb8b8b4075de2946a250156f81fb54) )
	ROM_LOAD16_BYTE( "c04-20.7g",    0x80000, 0x20000, CRC(7614c798) SHA1(7465f2eaeab73f047cc9f41f5a00173c34636513) )
	ROM_LOAD16_BYTE( "c04-22.9g",    0x80001, 0x20000, CRC(aa6e8da8) SHA1(014eb2b5ba89e267a915ea647a71fdd8413099c7) )
	ROM_LOAD16_BYTE( "c04-19.6",     0xc0000, 0x20000, CRC(231493ae) SHA1(2658e6556fd0e75ddd0f0b8628cfa5237c187a06) )
	ROM_LOAD16_BYTE( "c04-21.8",     0xc0001, 0x20000, CRC(8598d38e) SHA1(4ec1b819586b50e2f6aff2aaa5e3b06704b9bec2) )

	ROM_REGION( 0xc0000, "gfx1", 0 )	/* sprites 16x16 */
	ROM_LOAD16_BYTE( "c04-16.2g",  0x00000, 0x20000, CRC(1c6963a9) SHA1(2dc4b6838c95497e019c03582a8f7ecb48fa97a8) )
	ROM_LOAD16_BYTE( "c04-18.4g",  0x00001, 0x20000, CRC(67ea587f) SHA1(2b43ba53cc563d3462a4bec430427f92290f2b23) )
	ROM_LOAD16_BYTE( "c04-15.1",   0x40000, 0x20000, CRC(7c50b978) SHA1(aa9cad5f09f5d9dceaf4e06bcd347f1d5d02d292) )
	ROM_LOAD16_BYTE( "c04-17.3",   0x40001, 0x20000, CRC(c62fdeb8) SHA1(a9f6ca8335071169d772e65a9f5315a22a310b25) )
	ROM_LOAD16_BYTE( "c04-10.15",  0x80000, 0x10000, CRC(429b6b49) SHA1(dcb0c8bc9d67643d96b2ffdf5ccd747318704c37) )
	ROM_RELOAD     (               0xa0000, 0x10000 )
	ROM_LOAD16_BYTE( "c04-09.14",  0x80001, 0x10000, CRC(c78cf057) SHA1(097982e57b1d20fbdf21986c23684adefe6f1ce1) )
	ROM_RELOAD     (               0xa0001, 0x10000 )

	ROM_REGION( 0x10000, "audiocpu", 0 )     /* sound cpu */
	ROM_LOAD( "c04-06.71", 0x0000, 0x8000, CRC(b70106b2) SHA1(d71062f9d9b11492e13fc93982b95883f564f902) )
ROM_END

GAME( 2005, volfiedg, 0, volfied, volfied, driver_device, 0, ROT270, "GreekRoms", "Volfied (Greek)", MACHINE_SUPPORTS_SAVE )
