log_info("akhenaten: images started")

images = [
	// spr main
	{img: IMG_SLED_BRICKS, pack:PACK_SPR_MAIN, id:89},
	{img: IMG_SLED_SANDSTONE_SMALL, pack:PACK_SPR_MAIN, id:101},
	{img: IMG_SLED_STONE_SMALL, pack:PACK_SPR_MAIN, id:102},
	{img: IMG_SLED_GRANITE_SMALL, pack:PACK_SPR_MAIN, id:103},
	{img: IMG_SLED_LIMESTONE_SMALL, pack:PACK_GENERAL, id:104},
	// spr ambient
	{img: ANIM_SANDSTONE_QUARRY_2, pack:PACK_SPR_AMBIENT, id:49},

	// icon resources
	{img: IMG_RESOURCE_ICONS, pack:PACK_GENERAL, id:129},

	{img: IMG_SIDE_PANEL, pack:PACK_GENERAL, id:121, offset:0},
	{img: IMG_TOP_MENU_BACKGROUND, pack:PACK_GENERAL, id:121, offset:8},
	{img: IMG_EDITOR_SIDE_PANEL, pack:PACK_GENERAL, id:121, offset:0},
	{img: IMG_RESOURCE_PAPYRUS, pack:PACK_GENERAL, id:207, offset:0},
	{img: IMG_EMPIRE_ROUTE_HL_CLOSED, pack:PACK_GENERAL, id:149, offset:211},
	{img: IMG_EMPIRE_ROUTE_OPEN, pack:PACK_GENERAL, id:149, offset:201},
	{img: IMG_EMPIRE_ROUTE_HL_OPEN, pack:PACK_GENERAL, id:149, offset:186},
	{img: IMG_MINIMAP_BRIGHT_TEAL, pack:PACK_GENERAL, id:149, offset:170},
	{img: IMG_MINIMAP_DARK_RED, pack:PACK_GENERAL, id:149, offset:165},
	{img: IMG_MINIMAP_PURPLE, pack:PACK_GENERAL, id:149, offset:175},
	{img: IMG_MINIMAP_LIGHT_YELLOW, pack:PACK_GENERAL, id:149, offset:180},
	{img: IMG_MINIMAP_LILAC, pack:PACK_GENERAL, id:149, offset:195},
	{img: IMG_MINIMAP_SPENT_TEAL, pack:PACK_GENERAL, id:149, offset:200},
	{img: IMG_MINIMAP_COLOR, pack:PACK_GENERAL, id:149, offset:0},
	{img: IMG_TRADE_AMOUNT, pack:PACK_GENERAL, id:171, offset:0},
	{img: IMG_BRICKLAYER_WALK, pack:PACK_SPR_MAIN, id:109},
	{img: IMG_BRICKLAYER_DEATH, pack:PACK_SPR_MAIN, id:110},
	{img: IMG_BRICKLAYER_WORK, pack:PACK_SPR_MAIN, id:111},
	{img: IMG_BRICKLAYER_IDLE, pack:PACK_SPR_MAIN, id:112},
	{img: IMG_MONUMENT_ENTER, pack:PACK_GENERAL, id:114},
	{img: IMG_SLED_PULLER, pack:PACK_SPR_MAIN, id:121},
	{img: IMG_BIGSLED_EMPTY, pack:PACK_SPR_MAIN, id:166},
	{img: IMG_BIGSLED_STONE, pack:PACK_SPR_MAIN, id:167},
	{img: IMG_BIGSLED_SANDSTONE, pack:PACK_SPR_MAIN, id:168},
	{img: IMG_BIGSLED_GRANITE, pack:PACK_SPR_MAIN, id:169},
	{img: IMG_BIGSLED_LIMESTONE, pack:PACK_SPR_MAIN, id:170},
	{img: IMG_BIGSLED_CLAY, pack:PACK_SPR_MAIN, id:171},
	{img: IMG_BIGSLED_BRICKS, pack:PACK_SPR_MAIN, id:172},
	{img: IMG_SMALL_MASTABA_BRICKS, pack:PACK_MASTABA, id:1, offset:0},
	{img: IMG_ADVISOR_ICONS, pack:PACK_GENERAL, id:128, offset:0},
	{img: IMG_ADVISOR_BACKGROUND, pack:PACK_UNLOADED, id:2, offset:0},
	{img: IMG_PRIEST_OSIRIS, pack:PACK_SPR_MAIN, id:197, offset:0},
	{img: IMG_PRIEST_OSIRIS_DEATH, pack:PACK_SPR_MAIN, id:198, offset:0},
	{img: IMG_PRIEST_RA, pack:PACK_SPR_MAIN, id:210, offset:0},
	{img: IMG_PRIEST_RA_DEATH, pack:PACK_SPR_MAIN, id:211, offset:0},
	{img: IMG_PRIEST_PTAH, pack:PACK_SPR_MAIN, id:187, offset:0},
	{img: IMG_PRIEST_PTAH_DEATH, pack:PACK_SPR_MAIN, id:188, offset:0},
	{img: IMG_PRIEST_SETH, pack:PACK_SPR_MAIN, id:193, offset:0},
	{img: IMG_PRIEST_SETH_DEATH, pack:PACK_SPR_MAIN, id:194, offset:0},
	{img: IMG_PRIEST_BAST, pack:PACK_SPR_MAIN, id:208, offset:0},
	{img: IMG_PRIEST_BAST_DEATH, pack:PACK_SPR_MAIN, id:209, offset:0},
	{img: IMG_TERRAIN_FLOODPLAIN, pack:PACK_TERRAIN, id:31, offset:0},
]

cart_images = [
	{resource: RESOURCE_NONE, pack:PACK_SPR_MAIN, id:77 },
	{resource: RESOURCE_BARLEY, pack:PACK_SPR_MAIN, id:91 },
	{resource: RESOURCE_COPPER, pack:PACK_SPR_MAIN, id:107 },
	{resource: RESOURCE_BEER, pack:PACK_SPR_MAIN, id:92 },
	{resource: RESOURCE_PAPYRUS, pack:PACK_SPR_MAIN, id:100 },
]

cart_offsets = [
  {x:17, y:-7},
  {x:22, y:-1},
  {x:17, y:7},
  {x:0, 	y:11},
  {x:-17, y:6},
  {x:-22, y:-1},
  {x:-17, y:-7},
  {x:0, y:-12}
]

sled_offsets = [
  {x:-17, y:9},
  {x:22, y:-1},
  {x:-15, y:-5},
  {x:0, 	y:11},
  {x:12, y:-2},
  {x:-22, y:-1},
  {x:17, y:7},
  {x:0, y:-12}
]
