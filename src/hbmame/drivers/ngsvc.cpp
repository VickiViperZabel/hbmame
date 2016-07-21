// license:BSD-3-Clause
// copyright-holders:Robbbert
// SVCCHAOS SNK vs Capcom



DRIVER_INIT_MEMBER( neogeo_hbmame, svcd )
{
	DRIVER_INIT_CALL(neogeo);
	m_sprgen->m_fixed_layer_bank_type = 2;
	m_pvc_prot->svc_px_decrypt(cpuregion, cpuregion_size);
	m_pcm2_prot->neo_pcm2_swap(ym_region, ym_region_size, 3);
	m_pvc_prot->install_pvc_protection(m_maincpu, m_banked_cart);
	m_cmc_prot->neogeo_sfix_decrypt(spr_region, spr_region_size, fix_region, fix_region_size);
	svcpcb_s1data_decrypt();
}

DRIVER_INIT_MEMBER( neogeo_hbmame, svcd1 ) // decrypted C
{
	DRIVER_INIT_CALL(neogeo);
	m_sprgen->m_fixed_layer_bank_type = 2;
	m_pvc_prot->svc_px_decrypt(cpuregion, cpuregion_size);
	m_cmc_prot->neogeo_cmc50_m1_decrypt(audiocrypt_region, audiocrypt_region_size, audiocpu_region, audio_region_size);
	m_pvc_prot->install_pvc_protection(m_maincpu, m_banked_cart);
	m_pcm2_prot->neo_pcm2_swap(ym_region, ym_region_size, 3);
	m_cmc_prot->neogeo_sfix_decrypt(spr_region, spr_region_size, fix_region, fix_region_size);
}

DRIVER_INIT_MEMBER( neogeo_hbmame, svcplusb )
{
	DRIVER_INIT_CALL(neogeo);
	m_sprgen->m_fixed_layer_bank_type = 2;
}

DRIVER_INIT_MEMBER( neogeo_hbmame, svcplusd )
{
	DRIVER_INIT_CALL(neogeo);
	m_sprgen->m_fixed_layer_bank_type = 2;
	m_cmc_prot->neogeo_cmc50_m1_decrypt(audiocrypt_region, audiocrypt_region_size, audiocpu_region, audio_region_size);
}

DRIVER_INIT_MEMBER( neogeo_hbmame, svcpcd )
{
	DRIVER_INIT_CALL(neogeo);
	m_sprgen->m_fixed_layer_bank_type = 2;
	m_pvc_prot->svc_px_decrypt(cpuregion, cpuregion_size);
	m_cmc_prot->neogeo_cmc50_m1_decrypt(audiocrypt_region, audiocrypt_region_size, audiocpu_region, audio_region_size);
	m_pvc_prot->install_pvc_protection(m_maincpu, m_banked_cart);
	install_banked_bios();
	m_cmc_prot->neogeo_sfix_decrypt(spr_region, spr_region_size, fix_region, fix_region_size);
	svcpcb_s1data_decrypt();
}




ROM_START( svcd )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD32_WORD_SWAP( "269-p1.p1", 0x000000, 0x400000, CRC(38e2005e) SHA1(1b902905916a30969282f1399a756e32ff069097) )
	ROM_LOAD32_WORD_SWAP( "269-p2.p2", 0x000002, 0x400000, CRC(6d13797c) SHA1(3cb71a95cea6b006b44cac0f547df88aec0007b7) )

	NEO_SFIX_MT_512K

	NEO_BIOS_AUDIO_128K( "269d.m1", CRC(447b3123) SHA1(a09adc2c0ee2ee0f01287ceb97474a1a58093bd2) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269-v1.v1", 0x000000, 0x800000, CRC(c659b34c) SHA1(1931e8111ef43946f68699f8707334c96f753a1e) )
	ROM_LOAD( "269-v2.v2", 0x800000, 0x800000, CRC(dd903835) SHA1(e58d38950a7a8697bb22a1cc7a371ae6664ae8f9) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269d.c1", 0x0000000, 0x800000, CRC(465d473b) SHA1(0B2BE2B2657C2AE021EC91515D1D6306179751D5) )
	ROM_LOAD16_BYTE( "269d.c2", 0x0000001, 0x800000, CRC(3eb28f78) SHA1(DF1B096FE95796DB1515B69F74266ED13DD9EE56) )
	ROM_LOAD16_BYTE( "269d.c3", 0x1000000, 0x800000, CRC(f4d4ab2b) SHA1(A19788435173540469FE5D07429A83DDE6D701A0) )
	ROM_LOAD16_BYTE( "269d.c4", 0x1000001, 0x800000, CRC(a69d523a) SHA1(98D8DAC2E40F71B5B8426D3C77476A0A20783181) )
	ROM_LOAD16_BYTE( "269d.c5", 0x2000000, 0x800000, CRC(ba2a7892) SHA1(EED45E1330DCC9F610598DC53977BF3A81DD161A) )
	ROM_LOAD16_BYTE( "269d.c6", 0x2000001, 0x800000, CRC(37371ca1) SHA1(8AAA1B9EA34470085D9944C9AD64CFB0FFE09859) )
	ROM_LOAD16_BYTE( "269d.c7", 0x3000000, 0x800000, CRC(56ac5fb9) SHA1(74CB0D57060D25E35F76A9820F607633BD1B9C2C) )
	ROM_LOAD16_BYTE( "269d.c8", 0x3000001, 0x800000, CRC(de99e613) SHA1(F28C6AF4A31A937E5B441D4B860E3CCCA725F27A) )
ROM_END

ROM_START( svcd1 )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD32_WORD_SWAP( "269-p1.p1", 0x000000, 0x400000, CRC(38e2005e) SHA1(1b902905916a30969282f1399a756e32ff069097) )
	ROM_LOAD32_WORD_SWAP( "269-p2.p2", 0x000002, 0x400000, CRC(6d13797c) SHA1(3cb71a95cea6b006b44cac0f547df88aec0007b7) )

	NEO_SFIX_MT_512K

	NEO_BIOS_AUDIO_ENCRYPTED_512K( "269-m1.m1", CRC(f6819d00) SHA1(d3bbe09df502464f104e53501708ac6e2c1832c6) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269-v1.v1", 0x000000, 0x800000, CRC(c659b34c) SHA1(1931e8111ef43946f68699f8707334c96f753a1e) )
	ROM_LOAD( "269-v2.v2", 0x800000, 0x800000, CRC(dd903835) SHA1(e58d38950a7a8697bb22a1cc7a371ae6664ae8f9) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269d.c1", 0x0000000, 0x800000, CRC(465d473b) SHA1(0B2BE2B2657C2AE021EC91515D1D6306179751D5) )
	ROM_LOAD16_BYTE( "269d.c2", 0x0000001, 0x800000, CRC(3eb28f78) SHA1(DF1B096FE95796DB1515B69F74266ED13DD9EE56) )
	ROM_LOAD16_BYTE( "269d.c3", 0x1000000, 0x800000, CRC(f4d4ab2b) SHA1(A19788435173540469FE5D07429A83DDE6D701A0) )
	ROM_LOAD16_BYTE( "269d.c4", 0x1000001, 0x800000, CRC(a69d523a) SHA1(98D8DAC2E40F71B5B8426D3C77476A0A20783181) )
	ROM_LOAD16_BYTE( "269d.c5", 0x2000000, 0x800000, CRC(ba2a7892) SHA1(EED45E1330DCC9F610598DC53977BF3A81DD161A) )
	ROM_LOAD16_BYTE( "269d.c6", 0x2000001, 0x800000, CRC(37371ca1) SHA1(8AAA1B9EA34470085D9944C9AD64CFB0FFE09859) )
	ROM_LOAD16_BYTE( "269d1.c7", 0x3000000, 0x800000, CRC(5595b6cc) SHA1(9d6cc70f435401355b885475ccc3864825887656) )
	ROM_LOAD16_BYTE( "269d1.c8", 0x3000001, 0x800000, CRC(b17dfcf9) SHA1(46af296b12831ee40355f52d2c316f609557d6df) )
ROM_END

ROM_START( svcesv ) // all confirmed
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD32_WORD_SWAP( "269esv.p1", 0x000000, 0x400000, CRC(c6fd0131) SHA1(25439e469d0403439fde5d6532081a9b405bf642) )
	ROM_LOAD32_WORD_SWAP( "269esv.p2", 0x000002, 0x400000, CRC(2adede28) SHA1(555d3a9a53f0c7e8b450f7885b0ea86abece0843) )

	NEO_SFIX_MT_512K

	NEO_BIOS_AUDIO_ENCRYPTED_512K( "269-m1.m1", CRC(f6819d00) SHA1(d3bbe09df502464f104e53501708ac6e2c1832c6) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269-v1.v1", 0x000000, 0x800000, CRC(c659b34c) SHA1(1931e8111ef43946f68699f8707334c96f753a1e) )
	ROM_LOAD( "269-v2.v2", 0x800000, 0x800000, CRC(dd903835) SHA1(e58d38950a7a8697bb22a1cc7a371ae6664ae8f9) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269esv.c1", 0x0000000, 0x800000, CRC(03cda72a) SHA1(5557d44f191ed329256fd5dc383a7242ca30aee5) )
	ROM_LOAD16_BYTE( "269esv.c2", 0x0000001, 0x800000, CRC(442a7724) SHA1(8b7155978638a6656b0df9ccf7bd85be8172b167) )
	ROM_LOAD16_BYTE( "269esv.c3", 0x1000000, 0x800000, CRC(b311b183) SHA1(52b4c8c5530b856bbb497e5b33587cee0abfc892) )
	ROM_LOAD16_BYTE( "269esv.c4", 0x1000001, 0x800000, CRC(4aa13c41) SHA1(733c1434b65d2b595ba40d51045cfa523c14eefa) )
	ROM_LOAD16_BYTE( "269esv.c5", 0x2000000, 0x800000, CRC(1a81e716) SHA1(12d5f4128be45294aaf14461203ad99d768ad9bd) )
	ROM_LOAD16_BYTE( "269esv.c6", 0x2000001, 0x800000, CRC(6f346ae8) SHA1(a5561786bcdb51ffd72332c8da4a4448490a7068) )
	ROM_LOAD16_BYTE( "269esv.c7", 0x3000000, 0x800000, CRC(8dd412d3) SHA1(3d2afd7fc09c59537209071d049ec294f76770e5) )
	ROM_LOAD16_BYTE( "269esv.c8", 0x3000001, 0x800000, CRC(305ef23f) SHA1(3bdd24b075757062803ac2a6f9582bcfe0bcbb4c) )
ROM_END

ROM_START( svch )
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269h.p1", 0x000000, 0x600000, CRC(06435efb) SHA1(115d8dbad06565cfdd6b607cc2359ec3ae5db6e0) )

	//NEO_SFIX_128K( "269-s1h.bin", CRC(61ef88e5) )   rom not exist
	NEO_SFIX_128K( "269rm.s1", CRC(bc670454) SHA1(468641985fd3136235510bc48781039ef7b05c64) )

	NEO_BIOS_AUDIO_128K( "269h.m1", CRC(1bfa0f6f) SHA1(b59b02d73d5f9a32935db656f888caac6e622a20) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269h.v1", 0x000000, 0x400000, CRC(e7203930) SHA1(c6753df1db87d223ee39ffac920da449127dbcdf) )
	ROM_LOAD( "269h.v2", 0x400000, 0x400000, CRC(675159c3) SHA1(c3a4f6db61dfab5bc31bfe94e1c3915676347031) )
	ROM_LOAD( "269h.v3", 0x800000, 0x400000, CRC(f8810665) SHA1(fc1e94629a5124076959938257a80d04b2e871eb) )
	ROM_LOAD( "269h.v4", 0xc00000, 0x400000, CRC(b57b4ea3) SHA1(873dc7f5eae687bc70af01ea310e935287de0ebf) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269d.c1", 0x0000000, 0x800000, CRC(465d473b) SHA1(0B2BE2B2657C2AE021EC91515D1D6306179751D5) )
	ROM_LOAD16_BYTE( "269d.c2", 0x0000001, 0x800000, CRC(3eb28f78) SHA1(DF1B096FE95796DB1515B69F74266ED13DD9EE56) )
	ROM_LOAD16_BYTE( "269d.c3", 0x1000000, 0x800000, CRC(f4d4ab2b) SHA1(A19788435173540469FE5D07429A83DDE6D701A0) )
	ROM_LOAD16_BYTE( "269d.c4", 0x1000001, 0x800000, CRC(a69d523a) SHA1(98D8DAC2E40F71B5B8426D3C77476A0A20783181) )
	ROM_LOAD16_BYTE( "269d.c5", 0x2000000, 0x800000, CRC(ba2a7892) SHA1(EED45E1330DCC9F610598DC53977BF3A81DD161A) )
	ROM_LOAD16_BYTE( "269d.c6", 0x2000001, 0x800000, CRC(37371ca1) SHA1(8AAA1B9EA34470085D9944C9AD64CFB0FFE09859) )
	ROM_LOAD16_BYTE( "269d.c7", 0x3000000, 0x800000, CRC(56ac5fb9) SHA1(74CB0D57060D25E35F76A9820F607633BD1B9C2C) )
	ROM_LOAD16_BYTE( "269d.c8", 0x3000001, 0x800000, CRC(de99e613) SHA1(F28C6AF4A31A937E5B441D4B860E3CCCA725F27A) )
ROM_END

ROM_START( svcnd ) // only p1,vx,s1 confirmed
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269nd.p1", 0x000000, 0x600000, CRC(93855c0b) SHA1(03dd06ff5a11a37990bd0a9531beb44c63de2d91) )

	NEO_SFIX_MT_512K
	ROM_LOAD( "269nd.s1", 0x60000, 0x20000, CRC(ad184232) SHA1(6645d323d641004fa7a17e3b1e65613f398c95dd) )
	ROM_CONTINUE( 0x40000, 0x20000 )
	ROM_CONTINUE( 0x20000, 0x20000 )
	ROM_CONTINUE( 0x00000, 0x20000 )

	NEO_BIOS_AUDIO_ENCRYPTED_512K( "269-m1.m1", CRC(f6819d00) SHA1(d3bbe09df502464f104e53501708ac6e2c1832c6) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269pcbd.v1", 0x000000, 0x800000, CRC(ff64cd56) SHA1(e2754c554ed5ca14c2020c5d931021d5ac82660c) )
	ROM_LOAD( "269pcbd.v2", 0x800000, 0x800000, CRC(a8dd6446) SHA1(8972aab271c33f8af344bffe6359d9ddc4b8af2e) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269pcbd.c1", 0x0000000, 0x2000000, CRC(382ce01f) SHA1(8eec32f70169de83fc15df470aba9c51c312b577) )
	ROM_LOAD16_BYTE( "269pcbd.c2", 0x0000001, 0x2000000, CRC(88ad01ec) SHA1(da223bc09aa465ea6c15954c45fefbf3ee79a4d7) )
ROM_END

ROM_START( svcpcbd ) // JAMMA
	ROM_REGION( 0x2000000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269pcb.p1", 0x000000, 0x2000000, CRC(432cfdfc) SHA1(19b40d32188a8bace6d2d570c6cf3d2f1e31e379) )

	NEO_SFIX_MT_512K

	ROM_REGION16_BE( 0x80000, "mainbios", 0 )
	/* this contains both an ASIA and JAPAN bios, HARDDIP3 on the PCB selects which to use */
	ROM_LOAD16_WORD_SWAP( "sp-4x.sp1", 0x00000, 0x80000, CRC(b4590283) SHA1(47047ed5b6062babc0a0bebcc30e4b3f021e115a) )

	ROM_REGION( 0x80000, "audiocrypt", 0 )
	ROM_LOAD( "269-m1.m1", 0x00000, 0x80000, CRC(f6819d00) SHA1(d3bbe09df502464f104e53501708ac6e2c1832c6) )
	ROM_REGION( 0x90000, "audiocpu", ROMREGION_ERASEFF )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269pcbd.v1", 0x000000, 0x800000, CRC(ff64cd56) SHA1(e2754c554ed5ca14c2020c5d931021d5ac82660c) )
	ROM_LOAD( "269pcbd.v2", 0x800000, 0x800000, CRC(a8dd6446) SHA1(8972aab271c33f8af344bffe6359d9ddc4b8af2e) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269pcbd.c1", 0x0000000, 0x2000000, CRC(382ce01f) SHA1(8eec32f70169de83fc15df470aba9c51c312b577) )
	ROM_LOAD16_BYTE( "269pcbd.c2", 0x0000001, 0x2000000, CRC(88ad01ec) SHA1(da223bc09aa465ea6c15954c45fefbf3ee79a4d7) )
ROM_END

ROM_START( svcplusa2016 )
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269pa2016.p1", 0x000000, 0x454f9c, CRC(65471e6c) SHA1(32e07ec3d415940b3e1204e9e2ef00da60b4a685) )
	ROM_LOAD16_WORD_SWAP( "269pa2016.p2", 0x200000, 0x400000, CRC(f78b0e9e) SHA1(839091db9ecfc6720fa28790fca7c6c057ff42a7) )
	ROM_IGNORE( 0x054f62 )

	NEO_SFIX_MT_128K
	ROM_LOAD( "svc-s1pl.bin", 0x10000, 0x10000, CRC(ca3c735e) SHA1(aebd15253c90432a2e0a4c40f37110c1e2176ee4) )
	ROM_CONTINUE( 0x00000, 0x10000 )

	NEOGEO_BIOS

	ROM_REGION( 0x20000, "audiobios", 0 )
	ROM_LOAD( "sm1.sm1", 0x00000, 0x20000, CRC(94416d67) SHA1(42f9d7ddd6c0931fd64226a60dc73602b2819dcf) )

	ROM_REGION( 0x50000, "audiocpu", 0 )
	ROM_LOAD( "svc-m1.bin", 0x20000, 0x10000, CRC(804328c3) SHA1(f931636c563b0789d4812033a77b47bf663db43f) )
	ROM_CONTINUE( 0x00000, 0x10000 )
	ROM_COPY( "audiocpu", 0x000000, 0x10000, 0x10000 )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD16_WORD_SWAP( "svc-v2.bin", 0x000000, 0x400000, CRC(b5097287) SHA1(3ba3a9b5624879616382ed40337a3d9c50a0f314) )
	ROM_LOAD16_WORD_SWAP( "svc-v1.bin", 0x400000, 0x400000, CRC(bd3a391f) SHA1(972bf09b75e99a683ee965bec93b0da8f15d72d9) )
	ROM_LOAD16_WORD_SWAP( "svc-v4.bin", 0x800000, 0x400000, CRC(33fc0b37) SHA1(d61017d829f44c7df8795ba10c55c727d9972662) )
	ROM_LOAD16_WORD_SWAP( "svc-v3.bin", 0xc00000, 0x400000, CRC(aa9849a0) SHA1(9539b3356a070a066a89f27c287f316e7367ce2a) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "svc-c1.bin", 0x0000000, 0x800000, CRC(a7826b89) SHA1(3bbe348ce54b80b56ef032ea532a18ef3cafeb11) )
	ROM_LOAD16_BYTE( "svc-c2.bin", 0x0000001, 0x800000, CRC(ed3c2089) SHA1(b5d17692f15f5a678c273589fab2e3918711135e) )
	ROM_LOAD16_BYTE( "svc-c3.bin", 0x1000000, 0x800000, CRC(71ed8063) SHA1(ea1df9e2e382a8560a06d447421844cc588f43dd) )
	ROM_LOAD16_BYTE( "svc-c4.bin", 0x1000001, 0x800000, CRC(250bde2d) SHA1(8c72dcfceef6d022ab4b73ab37cf3ac0c3940c17) )
	ROM_LOAD16_BYTE( "svc-c5.bin", 0x2000000, 0x800000, CRC(9817c082) SHA1(1bea9c7220c2b1524896c86841d6d8fd55f5d366) )
	ROM_LOAD16_BYTE( "svc-c6.bin", 0x2000001, 0x800000, CRC(2bc0307f) SHA1(8090fa82c46eb503832359093c8cc3cee3141c90) )
	ROM_LOAD16_BYTE( "svc-c7.bin", 0x3000000, 0x800000, CRC(4358d7b9) SHA1(9270b58c2abc072a046bedda72f1395df26d0714) )
	ROM_LOAD16_BYTE( "svc-c8.bin", 0x3000001, 0x800000, CRC(366deee5) SHA1(d477ad7a5987fd6c7ef2c1680fbb7c884654590e) )
ROM_END

ROM_START( svcplusb )
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269plusb.p1", 0x000000, 0x600000, CRC(5D738F9A) SHA1(10AD161D6DE285659DCAEBBEA4AA2B384341E14D) )

	NEO_SFIX_MT_512K
	ROM_LOAD( "269plusb.s1", 0x60000, 0x20000, CRC(06125f98) SHA1(69ba2625c90bb09abf64f6d49d88d2ac2f1ee9ca) )
	ROM_CONTINUE( 0x40000, 0x20000 )
	ROM_CONTINUE( 0x20000, 0x20000 )
	ROM_CONTINUE( 0x00000, 0x20000 )

	NEO_BIOS_AUDIO_128K( "269rm.m1", CRC(fd602218) SHA1(d7af0af3e116a7c2f594d1ca77a1289b4e31cd7e) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269h.v1", 0x000000, 0x400000, CRC(e7203930) SHA1(c6753df1db87d223ee39ffac920da449127dbcdf) )
	ROM_LOAD( "269h.v2", 0x400000, 0x400000, CRC(675159c3) SHA1(c3a4f6db61dfab5bc31bfe94e1c3915676347031) )
	ROM_LOAD( "269h.v3", 0x800000, 0x400000, CRC(f8810665) SHA1(fc1e94629a5124076959938257a80d04b2e871eb) )
	ROM_LOAD( "269h.v4", 0xc00000, 0x400000, CRC(b57b4ea3) SHA1(873dc7f5eae687bc70af01ea310e935287de0ebf) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269d.c1", 0x0000000, 0x800000, CRC(465d473b) SHA1(0B2BE2B2657C2AE021EC91515D1D6306179751D5) )
	ROM_LOAD16_BYTE( "269d.c2", 0x0000001, 0x800000, CRC(3eb28f78) SHA1(DF1B096FE95796DB1515B69F74266ED13DD9EE56) )
	ROM_LOAD16_BYTE( "269d.c3", 0x1000000, 0x800000, CRC(f4d4ab2b) SHA1(A19788435173540469FE5D07429A83DDE6D701A0) )
	ROM_LOAD16_BYTE( "269d.c4", 0x1000001, 0x800000, CRC(a69d523a) SHA1(98D8DAC2E40F71B5B8426D3C77476A0A20783181) )
	ROM_LOAD16_BYTE( "269d.c5", 0x2000000, 0x800000, CRC(ba2a7892) SHA1(EED45E1330DCC9F610598DC53977BF3A81DD161A) )
	ROM_LOAD16_BYTE( "269d.c6", 0x2000001, 0x800000, CRC(37371ca1) SHA1(8AAA1B9EA34470085D9944C9AD64CFB0FFE09859) )
	ROM_LOAD16_BYTE( "269d.c7", 0x3000000, 0x800000, CRC(56ac5fb9) SHA1(74CB0D57060D25E35F76A9820F607633BD1B9C2C) )
	ROM_LOAD16_BYTE( "269d.c8", 0x3000001, 0x800000, CRC(de99e613) SHA1(F28C6AF4A31A937E5B441D4B860E3CCCA725F27A) )
ROM_END

ROM_START( svcplusd ) // only p1,vx,cx confirmed
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269plusd.p1", 0x000000, 0x600000, CRC(2a57e4d4) SHA1(09fec6b376adfb2b051cd281f66b483e2deffa60) )

	NEO_SFIX_MT_512K // This one contains PLUS logo
	ROM_LOAD( "269plusb.s1", 0x60000, 0x20000, CRC(06125f98) SHA1(69ba2625c90bb09abf64f6d49d88d2ac2f1ee9ca) )
	ROM_CONTINUE( 0x40000, 0x20000 )
	ROM_CONTINUE( 0x20000, 0x20000 )
	ROM_CONTINUE( 0x00000, 0x20000 )

	NEO_BIOS_AUDIO_ENCRYPTED_512K( "269-m1.m1", CRC(f6819d00) SHA1(d3bbe09df502464f104e53501708ac6e2c1832c6) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269pcbd.v1", 0x000000, 0x800000, CRC(ff64cd56) SHA1(e2754c554ed5ca14c2020c5d931021d5ac82660c) )
	ROM_LOAD( "269pcbd.v2", 0x800000, 0x800000, CRC(a8dd6446) SHA1(8972aab271c33f8af344bffe6359d9ddc4b8af2e) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269pcbd.c1", 0x0000000, 0x2000000, CRC(382ce01f) SHA1(8eec32f70169de83fc15df470aba9c51c312b577) )
	ROM_LOAD16_BYTE( "269pcbd.c2", 0x0000001, 0x2000000, CRC(88ad01ec) SHA1(da223bc09aa465ea6c15954c45fefbf3ee79a4d7) )
ROM_END

ROM_START( svcpryu )
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269pryu.p1", 0x000000, 0x600000, CRC(2088fa5c) SHA1(a60c01aef8532825dfde4a6ccc7c97692dd70e64) )

	NEO_SFIX_128K( "269rm.s1", CRC(bc670454) SHA1(468641985fd3136235510bc48781039ef7b05c64) )

	NEO_BIOS_AUDIO_128K( "269pryu.m1", CRC(dcc67f10) SHA1(acdd75144f90d2b135181a4fd2c6c72c240c66b0) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269h.v1", 0x000000, 0x400000, CRC(e7203930) SHA1(c6753df1db87d223ee39ffac920da449127dbcdf) )
	ROM_LOAD( "269h.v2", 0x400000, 0x400000, CRC(675159c3) SHA1(c3a4f6db61dfab5bc31bfe94e1c3915676347031) )
	ROM_LOAD( "269h.v3", 0x800000, 0x400000, CRC(f8810665) SHA1(fc1e94629a5124076959938257a80d04b2e871eb) )
	ROM_LOAD( "269h.v4", 0xc00000, 0x400000, CRC(b57b4ea3) SHA1(873dc7f5eae687bc70af01ea310e935287de0ebf) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269d.c1", 0x0000000, 0x800000, CRC(465d473b) SHA1(0B2BE2B2657C2AE021EC91515D1D6306179751D5) )
	ROM_LOAD16_BYTE( "269d.c2", 0x0000001, 0x800000, CRC(3eb28f78) SHA1(DF1B096FE95796DB1515B69F74266ED13DD9EE56) )
	ROM_LOAD16_BYTE( "269d.c3", 0x1000000, 0x800000, CRC(f4d4ab2b) SHA1(A19788435173540469FE5D07429A83DDE6D701A0) )
	ROM_LOAD16_BYTE( "269d.c4", 0x1000001, 0x800000, CRC(a69d523a) SHA1(98D8DAC2E40F71B5B8426D3C77476A0A20783181) )
	ROM_LOAD16_BYTE( "269d.c5", 0x2000000, 0x800000, CRC(ba2a7892) SHA1(EED45E1330DCC9F610598DC53977BF3A81DD161A) )
	ROM_LOAD16_BYTE( "269d.c6", 0x2000001, 0x800000, CRC(37371ca1) SHA1(8AAA1B9EA34470085D9944C9AD64CFB0FFE09859) )
	ROM_LOAD16_BYTE( "269d.c7", 0x3000000, 0x800000, CRC(56ac5fb9) SHA1(74CB0D57060D25E35F76A9820F607633BD1B9C2C) )
	ROM_LOAD16_BYTE( "269d.c8", 0x3000001, 0x800000, CRC(de99e613) SHA1(F28C6AF4A31A937E5B441D4B860E3CCCA725F27A) )
ROM_END

ROM_START( svcps2 )
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269ps2.p1", 0x000000, 0x600000, CRC(aa15036f) SHA1(e57df12f02d2a7fa2b5eda99c90ae49c3ced44b0) )

	NEO_SFIX_128K( "269rm.s1", CRC(bc670454) SHA1(468641985fd3136235510bc48781039ef7b05c64) )

	NEO_BIOS_AUDIO_128K( "269h.m1", CRC(1bfa0f6f) SHA1(b59b02d73d5f9a32935db656f888caac6e622a20) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269h.v1", 0x000000, 0x400000, CRC(e7203930) SHA1(c6753df1db87d223ee39ffac920da449127dbcdf) )
	ROM_LOAD( "269h.v2", 0x400000, 0x400000, CRC(675159c3) SHA1(c3a4f6db61dfab5bc31bfe94e1c3915676347031) )
	ROM_LOAD( "269h.v3", 0x800000, 0x400000, CRC(f8810665) SHA1(fc1e94629a5124076959938257a80d04b2e871eb) )
	ROM_LOAD( "269h.v4", 0xc00000, 0x400000, CRC(b57b4ea3) SHA1(873dc7f5eae687bc70af01ea310e935287de0ebf) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269d.c1", 0x0000000, 0x800000, CRC(465d473b) SHA1(0B2BE2B2657C2AE021EC91515D1D6306179751D5) )
	ROM_LOAD16_BYTE( "269d.c2", 0x0000001, 0x800000, CRC(3eb28f78) SHA1(DF1B096FE95796DB1515B69F74266ED13DD9EE56) )
	ROM_LOAD16_BYTE( "269d.c3", 0x1000000, 0x800000, CRC(f4d4ab2b) SHA1(A19788435173540469FE5D07429A83DDE6D701A0) )
	ROM_LOAD16_BYTE( "269d.c4", 0x1000001, 0x800000, CRC(a69d523a) SHA1(98D8DAC2E40F71B5B8426D3C77476A0A20783181) )
	ROM_LOAD16_BYTE( "269d.c5", 0x2000000, 0x800000, CRC(ba2a7892) SHA1(EED45E1330DCC9F610598DC53977BF3A81DD161A) )
	ROM_LOAD16_BYTE( "269d.c6", 0x2000001, 0x800000, CRC(37371ca1) SHA1(8AAA1B9EA34470085D9944C9AD64CFB0FFE09859) )
	ROM_LOAD16_BYTE( "svcps2_c7.rom", 0x3000000, 0x800000, CRC(361c97ab) SHA1(3b3672630c54ddbee38932f7d27d27d71e9fe19c) )
	ROM_LOAD16_BYTE( "svcps2_c8.rom", 0x3000001, 0x800000, CRC(1a16e266) SHA1(3d6a07716b79b62c8f2240c8be83d662b35f615a) )
ROM_END

ROM_START( svcrm )
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269rm.p1", 0x000000, 0x600000, CRC(9d39234f) SHA1(a28ba0b53a9f7dc2d0b3dfd22025ebddbd8c99af) )

	NEO_SFIX_128K( "269rm.s1", CRC(bc670454) SHA1(468641985fd3136235510bc48781039ef7b05c64) )

	NEO_BIOS_AUDIO_128K( "269rm.m1", CRC(fd602218) SHA1(d7af0af3e116a7c2f594d1ca77a1289b4e31cd7e) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269h.v1", 0x000000, 0x400000, CRC(e7203930) SHA1(c6753df1db87d223ee39ffac920da449127dbcdf) )
	ROM_LOAD( "269h.v2", 0x400000, 0x400000, CRC(675159c3) SHA1(c3a4f6db61dfab5bc31bfe94e1c3915676347031) )
	ROM_LOAD( "269h.v3", 0x800000, 0x400000, CRC(f8810665) SHA1(fc1e94629a5124076959938257a80d04b2e871eb) )
	ROM_LOAD( "269h.v4", 0xc00000, 0x400000, CRC(b57b4ea3) SHA1(873dc7f5eae687bc70af01ea310e935287de0ebf) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269d.c1", 0x0000000, 0x800000, CRC(465d473b) SHA1(0B2BE2B2657C2AE021EC91515D1D6306179751D5) )
	ROM_LOAD16_BYTE( "269d.c2", 0x0000001, 0x800000, CRC(3eb28f78) SHA1(DF1B096FE95796DB1515B69F74266ED13DD9EE56) )
	ROM_LOAD16_BYTE( "269d.c3", 0x1000000, 0x800000, CRC(f4d4ab2b) SHA1(A19788435173540469FE5D07429A83DDE6D701A0) )
	ROM_LOAD16_BYTE( "269d.c4", 0x1000001, 0x800000, CRC(a69d523a) SHA1(98D8DAC2E40F71B5B8426D3C77476A0A20783181) )
	ROM_LOAD16_BYTE( "269d.c5", 0x2000000, 0x800000, CRC(ba2a7892) SHA1(EED45E1330DCC9F610598DC53977BF3A81DD161A) )
	ROM_LOAD16_BYTE( "269d.c6", 0x2000001, 0x800000, CRC(37371ca1) SHA1(8AAA1B9EA34470085D9944C9AD64CFB0FFE09859) )
	ROM_LOAD16_BYTE( "269d.c7", 0x3000000, 0x800000, CRC(56ac5fb9) SHA1(74CB0D57060D25E35F76A9820F607633BD1B9C2C) )
	ROM_LOAD16_BYTE( "269d.c8", 0x3000001, 0x800000, CRC(de99e613) SHA1(F28C6AF4A31A937E5B441D4B860E3CCCA725F27A) )
ROM_END

ROM_START( svcsplus2016 )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "svc-p1sp.bin", 0x000000, 0x400000, CRC(2601902f) SHA1(202348a13c6480f7de37a3ee983823838822fc98) )
	ROM_LOAD16_WORD_SWAP( "269sp2016.p2", 0x400000, 0x400000, CRC(c30b4d6c) SHA1(5bd2cc39e988e2c8c92e0df3f75b8343cec5b09c) )
	ROM_IGNORE( 0x054f4c )

	NEO_SFIX_128K( "svc-s1sp.bin", CRC(233d6439) SHA1(369024c7a2405c3144c14ac016c07c3dc0f44187) )

	NEOGEO_BIOS

	ROM_REGION( 0x20000, "audiobios", 0 )
	ROM_LOAD( "sm1.sm1", 0x00000, 0x20000, CRC(94416d67) SHA1(42f9d7ddd6c0931fd64226a60dc73602b2819dcf) )

	ROM_REGION( 0x50000, "audiocpu", 0 )
	ROM_LOAD( "svc-m1.bin", 0x20000, 0x10000, CRC(804328c3) SHA1(f931636c563b0789d4812033a77b47bf663db43f) )
	ROM_CONTINUE( 0x00000, 0x10000 )
	ROM_COPY( "audiocpu", 0x000000, 0x10000, 0x10000 )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD16_WORD_SWAP( "svc-v2.bin", 0x000000, 0x400000, CRC(b5097287) SHA1(3ba3a9b5624879616382ed40337a3d9c50a0f314) )
	ROM_LOAD16_WORD_SWAP( "svc-v1.bin", 0x400000, 0x400000, CRC(bd3a391f) SHA1(972bf09b75e99a683ee965bec93b0da8f15d72d9) )
	ROM_LOAD16_WORD_SWAP( "svc-v4.bin", 0x800000, 0x400000, CRC(33fc0b37) SHA1(d61017d829f44c7df8795ba10c55c727d9972662) )
	ROM_LOAD16_WORD_SWAP( "svc-v3.bin", 0xc00000, 0x400000, CRC(aa9849a0) SHA1(9539b3356a070a066a89f27c287f316e7367ce2a) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "svc-c1.bin", 0x0000000, 0x800000, CRC(a7826b89) SHA1(3bbe348ce54b80b56ef032ea532a18ef3cafeb11) )
	ROM_LOAD16_BYTE( "svc-c2.bin", 0x0000001, 0x800000, CRC(ed3c2089) SHA1(b5d17692f15f5a678c273589fab2e3918711135e) )
	ROM_LOAD16_BYTE( "svc-c3.bin", 0x1000000, 0x800000, CRC(71ed8063) SHA1(ea1df9e2e382a8560a06d447421844cc588f43dd) )
	ROM_LOAD16_BYTE( "svc-c4.bin", 0x1000001, 0x800000, CRC(250bde2d) SHA1(8c72dcfceef6d022ab4b73ab37cf3ac0c3940c17) )
	ROM_LOAD16_BYTE( "svc-c5.bin", 0x2000000, 0x800000, CRC(9817c082) SHA1(1bea9c7220c2b1524896c86841d6d8fd55f5d366) )
	ROM_LOAD16_BYTE( "svc-c6.bin", 0x2000001, 0x800000, CRC(2bc0307f) SHA1(8090fa82c46eb503832359093c8cc3cee3141c90) )
	ROM_LOAD16_BYTE( "svc-c7.bin", 0x3000000, 0x800000, CRC(4358d7b9) SHA1(9270b58c2abc072a046bedda72f1395df26d0714) )
	ROM_LOAD16_BYTE( "svc-c8.bin", 0x3000001, 0x800000, CRC(366deee5) SHA1(d477ad7a5987fd6c7ef2c1680fbb7c884654590e) )
ROM_END

ROM_START( svcspryu )
	ROM_REGION( 0x600000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "269spryu.p1", 0x000000, 0x600000, CRC(4f15b6b3) SHA1(651e5340b5442ff6cd9b6a325ea6ad8abc116cfb) )

	NEO_SFIX_128K( "269rm.s1", CRC(bc670454) SHA1(468641985fd3136235510bc48781039ef7b05c64) )

	NEO_BIOS_AUDIO_128K( "269pryu.m1", CRC(dcc67f10) SHA1(acdd75144f90d2b135181a4fd2c6c72c240c66b0) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "269h.v1", 0x000000, 0x400000, CRC(e7203930) SHA1(c6753df1db87d223ee39ffac920da449127dbcdf) )
	ROM_LOAD( "269h.v2", 0x400000, 0x400000, CRC(675159c3) SHA1(c3a4f6db61dfab5bc31bfe94e1c3915676347031) )
	ROM_LOAD( "269h.v3", 0x800000, 0x400000, CRC(f8810665) SHA1(fc1e94629a5124076959938257a80d04b2e871eb) )
	ROM_LOAD( "269h.v4", 0xc00000, 0x400000, CRC(b57b4ea3) SHA1(873dc7f5eae687bc70af01ea310e935287de0ebf) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "269d.c1", 0x0000000, 0x800000, CRC(465d473b) SHA1(0B2BE2B2657C2AE021EC91515D1D6306179751D5) )
	ROM_LOAD16_BYTE( "269d.c2", 0x0000001, 0x800000, CRC(3eb28f78) SHA1(DF1B096FE95796DB1515B69F74266ED13DD9EE56) )
	ROM_LOAD16_BYTE( "269d.c3", 0x1000000, 0x800000, CRC(f4d4ab2b) SHA1(A19788435173540469FE5D07429A83DDE6D701A0) )
	ROM_LOAD16_BYTE( "269d.c4", 0x1000001, 0x800000, CRC(a69d523a) SHA1(98D8DAC2E40F71B5B8426D3C77476A0A20783181) )
	ROM_LOAD16_BYTE( "269d.c5", 0x2000000, 0x800000, CRC(ba2a7892) SHA1(EED45E1330DCC9F610598DC53977BF3A81DD161A) )
	ROM_LOAD16_BYTE( "269d.c6", 0x2000001, 0x800000, CRC(37371ca1) SHA1(8AAA1B9EA34470085D9944C9AD64CFB0FFE09859) )
	ROM_LOAD16_BYTE( "269d.c7", 0x3000000, 0x800000, CRC(56ac5fb9) SHA1(74CB0D57060D25E35F76A9820F607633BD1B9C2C) )
	ROM_LOAD16_BYTE( "269d.c8", 0x3000001, 0x800000, CRC(de99e613) SHA1(F28C6AF4A31A937E5B441D4B860E3CCCA725F27A) )
ROM_END



GAME( 2003, svcd,          svc,      neogeo_noslot,   neogeo,   neogeo_hbmame,       svcd,     ROT0, "hack", "SvC Chaos (decrypted C set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcd1,         svc,      neogeo_noslot,   neogeo,   neogeo_hbmame,       svcd1,    ROT0, "hack", "SvC Chaos (decrypted C set 2)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svch,          svc,      neogeo_noslot,   neogeo,   neogeo_state,        neogeo,   ROT0, "chbandy", "SvC Chaos (Remix Ver 1.0 by chbandy)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcesv,        svc,      neogeo_noslot,   neogeo,   neogeo_noslot_state, svc,      ROT0, "hack", "SvC Chaos (unknown esv)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcnd,         svc,      neogeo_noslot,   neogeo,   neogeo_hbmame,       svcplusd, ROT0, "hack", "SvC Chaos (unknown nd)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcpcbd,       svcpcb,   neogeo_noslot,   dualbios, neogeo_hbmame,       svcpcd,   ROT0, "hack", "SvC Chaos (JAMMA PCB, decrypted C & V)", MACHINE_SUPPORTS_SAVE )
GAME( 2016, svcplusa2016,  svc,      neogeo_noslot,   neogeo,   neogeo_noslot_state, svcplusa, ROT0, "hack", "SvC Chaos PLUS (2016)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcplusb,      svc,      neogeo_noslot,   neogeo,   neogeo_hbmame,       svcplusb, ROT0, "hack", "SvC Chaos PLUS (Bootleg, set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcplusd,      svc,      neogeo_noslot,   neogeo,   neogeo_hbmame,       svcplusd, ROT0, "hack", "SvC Chaos PLUS (unknown plusd)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcpryu,       svc,      neogeo_noslot,   neogeo,   neogeo_state,        neogeo,   ROT0, "hack", "SvC Plus (Koryu)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcps2,        svc,      neogeo_noslot,   neogeo,   neogeo_state,        neogeo,   ROT0, "EGHT", "SvC Playstation2 Hack Final 1.02 (EGHT)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcrm,         svc,      neogeo_noslot,   neogeo,   neogeo_state,        neogeo,   ROT0, "Jason", "SvC REMIX ULTRA (Ver 1.2 by Jason)", MACHINE_SUPPORTS_SAVE )
GAME( 2016, svcsplus2016,  svc,      neogeo_noslot,   neogeo,   neogeo_noslot_state, svcsplus, ROT0, "hack", "SvC Chaos Super Plus (2016)", MACHINE_SUPPORTS_SAVE )
GAME( 2003, svcspryu,      svc,      neogeo_noslot,   neogeo,   neogeo_state,        neogeo,   ROT0, "hack", "SvC Plus (Super Koryu)", MACHINE_SUPPORTS_SAVE )
