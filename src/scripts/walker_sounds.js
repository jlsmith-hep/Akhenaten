log_info("Ozymandias: walker sounds started")

walker_sounds = [
 {type: "apothecary_no_threat_malaria_here", 						sound:"apothecary_e02.wav"},
 {type: "apothecary_have_malaria_risk_here", 						sound:"apothecary_e03.wav"},
 {type: "artisan_work_my_tools_need_for_monument", 			sound:"artisan_e01.wav"},
 {type: "artisan_work_i_write_history_of_egypt", 				sound:"artisan_e02.wav"},
 {type: "barge_have_no_place_for_dock", 								sound:"barge_e01.wav"},
 {type: "barge_docked_wait_for_dockpushers", 						sound:"barge_e02.wav"},
 {type: "barge_city_not_trades", 												sound:"barge_e03.wav"},
 {type: "barge_i_like_to_trage", 												sound:"barge_e04.wav"},
 {type: "barge_amazing_trades", 												sound:"barge_e05.wav"},
 {type: "brick_time_to_put_bricks", 										sound:"brick_e01.wav"},
 {type: "brick_with_my_bricks_monuments_will_be_fine", 	sound:"brick_e02.wav"},
 {type: "caravan_city_not_trades", 											sound:"caravan_e01.wav"},
 {type: "caravan_buy_for_less_sell_for_more", 					sound:"caravan_e02.wav"},
 {type: "caravan_its_my_life", 													sound:"caravan_e03.wav"},
 {type: "caravan_amazing_trades", 											sound:"caravan_e04.wav"},
 {type: "caravan_bad_trades", 													sound:"caravan_e05.wav"},
 {type: "carpenter_work_my_tools_need_for_monument", 		sound:"carpenter_e01.wav"},
 {type: "carpenter_this_monument_will_be_short", 				sound:"carpenter_e02.wav"},
 {type: "cartpusher_have_no_place_for_goods", 					sound:"cartpusher_e01.wav"},
 {type: "cartpusher_i_have_time_for_rest", 							sound:"cartpusher_e02.wav"},
 {type: "cart_pusher_road_too_long", 										sound:"cartpusher_e03.wav"},
 {type: "market_buyer_goto_store", 											sound:"mkt_buyer_e01.wav"},
 {type: "market_buyer_back_to_market", 									sound:"mkt_buyer_e02.wav"},
 {type: "emigrant_no_job_in_city", 											sound: "emigrant_e01.wav"},
 {type: "emigrant_no_food_in_city", 										sound: "emigrant_e02.wav"},
 {type: "emigrant_tax_too_high", 												sound: "emigrant_e03.wav"},
 {type: "emigrant_salary_too_low", 											sound: "emigrant_e04.wav"},
 {type: "emigrant_no_house_for_me", 										sound: "emigrant_e05.wav"},
 {type: "physician_desease_can_start_at_any_moment", 		sound: "doctor_e01.wav"},
 {type: "physician_city_has_low_health", 								sound: "doctor_g01.wav"},
 {type: "physician_no_food_in_city", 										sound: "doctor_g02.wav"},
 {type: "physician_enemies_in_city", 										sound: "doctor_g03.wav"},
 {type: "physician_need_workers", 											sound: "doctor_g04.wav"},
 {type: "physician_gods_are_angry", 										sound: "doctor_g05.wav"},
 {type: "physician_gods_are_pleasures", 								sound: "doctor_g06.wav"},
 {type: "physician_no_job_in_city", 										sound: "doctor_g07.wav"},
 {type: "physician_low_entertainment", 									sound: "doctor_g08.wav"},
 {type: "physician_all_good_in_city", 									sound: "doctor_g09.wav"},
 {type: "physician_city_very_healthy", 									sound: "doctor_g10.wav"},
 {type: "immigrant_i_hope_i_need_here", 								sound: "immigrant_e01.wav"},
 {type: "immigrant_i_heard_city_have_work_for_all", 		sound: "immigrant_e02.wav"},
 {type: "immigrant_i_heard_city_have_cheap_food", 			sound: "immigrant_e03.wav"},
 {type: "cartpusher_i_have_no_destination", 						sound: "cartpusher_e01.wav"},
 {type: "cartpusher_back_to_home", 											sound: "cartpusher_e02.wav"},
 {type: "cartpusher_delivering_items", 									sound: "cartpusher_e03.wav"},
 {type: "laborseeker_no_jobs", 													sound: "Labor_e01.wav"},
 {type: "laborseeker_need_workers", 										sound: "Labor_e02.WAV"},
 {type: "laborseeker_disease_in_city", 									sound: "Labor_g01.WAV"},
 {type: "laborseeker_i_looking_for_the_workers", 				sound: "Labor_g02.WAV"},
 {type: "laborseeker_city_not_safety_workers_leaving",	sound: "Labor_g03.WAV"},
 {type: "laborseeker_need_more_workers",  							sound: "Labor_g04.WAV"},
 {type: "laborseeker_gods_are_angry", 									sound: "Labor_g05.WAV"},
 {type: "laborseeker_no_food_in_city", 									sound: "Labor_g06.WAV"},
 {type: "laborseeker_much_unemployments", 							sound: "Labor_g07.WAV"},
 {type: "laborseeker_no_some_workers", 									sound: "Labor_g08.WAV"},
 {type: "laborseeker_i_want_to_leave_city", 						sound: "Labor_g09.WAV"},
 {type: "laborseeker_city_is_amazing", 									sound: "Labor_g10.WAV"},
 {type: "fireman_fighting_fire", 												sound: "fireman_e01.wav"},
 {type: "fireman_going_to_fire", 												sound: "fireman_e02.wav"},
 {type: "fireman_fighting_fire_also", 									sound: "fireman_e03.WAV"},
 {type: "fireman_desease_can_start_at_any_moment", 			sound: "fireman_g01.WAV"},
 {type: "fireman_no_food_in_city", 											sound: "fireman_g02.WAV"},
 {type: "fireman_city_not_safety_workers_leaving", 			sound: "fireman_g03.WAV"},
 {type: "fireman_need_workers", 												sound: "fireman_g04.WAV"},
 {type: "fireman_hight_fire_level", 										sound: "fireman_g05.WAV"},
 {type: "fireman_gods_are_angry", 											sound: "fireman_g06.WAV"},
 {type: "fireman_need_more_workers", 										sound: "fireman_g07.WAV"},
 {type: "fireman_low_entertainment", 										sound: "fireman_g08.WAV"},
 {type: "fireman_gods_are_pleasures", 									sound: "fireman_g09.WAV"},
 {type: "fireman_city_is_amazing", 											sound: "fireman_g10.wav"},
 {type: "", sound: "emigrant_e02.wav"},
 {type: "", sound: "emigrant_e03.wav"},
 {type: "", sound: "emigrant_e04.wav"},
 {type: "", sound: "emigrant_e05.wav"},
 {type: "", sound: "engineer_e01.wav"},
 {type: "", sound: "engineer_e02.wav"},
 {type: "", sound: "engineer_g01.wav"},
 {type: "", sound: "engineer_g02.wav"},
 {type: "", sound: "engineer_g03.wav"},
 {type: "", sound: "engineer_g04.wav"},
 {type: "", sound: "engineer_g05.wav"},
 {type: "", sound: "engineer_g06.wav"},
 {type: "", sound: "engineer_g07.wav"},
 {type: "", sound: "engineer_g08.wav"},
 {type: "", sound: "engineer_g09.wav"},
 {type: "", sound: "engineer_g10.wav"},
 {type: "", sound: "fireman_e01.wav"},
 {type: "", sound: "fireman_e02.wav"},
 {type: "", sound: "fireman_e03.wav"},
 {type: "", sound: "fireman_g01.wav"},
 {type: "", sound: "fireman_g02.wav"},
 {type: "", sound: "fireman_g03.wav"},
 {type: "", sound: "fireman_g04.wav"},
 {type: "", sound: "fireman_g05.wav"},
 {type: "", sound: "fireman_g06.wav"},
 {type: "", sound: "fireman_g07.wav"},
 {type: "", sound: "fireman_g08.wav"},
 {type: "", sound: "fireman_g09.wav"},
 {type: "", sound: "fireman_g10.wav"},
 {type: "", sound: "fishing_e01.wav"},
 {type: "", sound: "fishing_e02.wav"},
 {type: "", sound: "fishing_e03.wav"},
 {type: "", sound: "governor_e01.WAV"},
 {type: "", sound: "governor_e02.WAV"},
 {type: "", sound: "guard_e01.wav"},
 {type: "", sound: "guard_e02.wav"},
 {type: "", sound: "guard_e03.wav"},
 {type: "", sound: "guard_e04.wav"},
 {type: "", sound: "hunt_ant_e01.wav"},
 {type: "", sound: "hunt_ant_e02.wav"},
 {type: "", sound: "hunt_bird_e01.wav"},
 {type: "", sound: "hunt_bird_e02.wav"},
 {type: "", sound: "hunt_ostrich_e01.wav"},
 {type: "", sound: "hunt_ostrich_e02.wav"},
 {type: "", sound: "immigrant_e01.wav"},
 {type: "", sound: "immigrant_e02.wav"},
 {type: "", sound: "immigrant_e03.wav"},
 {type: "", sound: "juggler_e01.wav"},
 {type: "", sound: "juggler_g01.wav"},
 {type: "", sound: "juggler_g02.wav"},
 {type: "", sound: "juggler_g03.wav"},
 {type: "", sound: "juggler_g04.wav"},
 {type: "", sound: "juggler_g05.wav"},
 {type: "", sound: "juggler_g06.wav"},
 {type: "", sound: "juggler_g07.wav"},
 {type: "", sound: "juggler_g08.wav"},
 {type: "", sound: "juggler_g09.wav"},
 {type: "", sound: "juggler_g10.wav"},
 {type: "", sound: "Labor_e01.wav"},
 {type: "", sound: "Labor_e02.wav"},
 {type: "", sound: "Labor_g01.wav"},
 {type: "", sound: "Labor_g02.wav"},
 {type: "", sound: "Labor_g03.wav"},
 {type: "", sound: "Labor_g04.wav"},
 {type: "", sound: "Labor_g05.wav"},
 {type: "", sound: "Labor_g06.wav"},
 {type: "", sound: "Labor_g07.wav"},
 {type: "", sound: "Labor_g08.wav"},
 {type: "", sound: "Labor_g09.wav"},
 {type: "", sound: "Labor_g10.wav"},
 {type: "", sound: "library_e01.wav"},
 {type: "", sound: "library_g01.wav"},
 {type: "", sound: "library_g02.wav"},
 {type: "", sound: "library_g03.wav"},
 {type: "", sound: "library_g04.wav"},
 {type: "", sound: "library_g05.wav"},
 {type: "", sound: "library_g06.wav"},
 {type: "", sound: "library_g07.wav"},
 {type: "", sound: "library_g08.wav"},
 {type: "", sound: "library_g09.wav"},
 {type: "", sound: "library_g10.wav"},
 {type: "", sound: "magistrate_e02.wav"},
 {type: "", sound: "magistrate_e03.wav"},
 {type: "", sound: "magistrate_e04.wav"},
 {type: "", sound: "magistrate_e05.wav"},
 {type: "", sound: "magistrate_g01.wav"},
 {type: "", sound: "magistrate_g02.wav"},
 {type: "", sound: "magistrate_g03.wav"},
 {type: "", sound: "magistrate_g04.wav"},
 {type: "", sound: "magistrate_g05.wav"},
 {type: "", sound: "magistrate_g06.wav"},
 {type: "", sound: "magistrate_g07.wav"},
 {type: "", sound: "magistrate_g08.wav"},
 {type: "", sound: "magistrate_g09.wav"},
 {type: "", sound: "magistrate_g10.wav"},
 {type: "", sound: "marketboy_e01.wav"},
 {type: "", sound: "marketboy_e02.wav"},
 {type: "", sound: "marketboy_e03.wav"},
 {type: "", sound: "mkt_buyer_e01.wav"},
 {type: "", sound: "mkt_buyer_e02.wav"},
 {type: "", sound: "mkt_buyer_g01.wav"},
 {type: "", sound: "mkt_buyer_g02.wav"},
 {type: "", sound: "mkt_buyer_g03.wav"},
 {type: "", sound: "mkt_buyer_g04.wav"},
 {type: "", sound: "mkt_buyer_g05.wav"},
 {type: "", sound: "mkt_buyer_g06.wav"},
 {type: "", sound: "mkt_buyer_g07.wav"},
 {type: "", sound: "mkt_buyer_g08.wav"},
 {type: "", sound: "mkt_buyer_g09.wav"},
 {type: "", sound: "mkt_buyer_g10.wav"},
 {type: "", sound: "mkt_seller_e01.wav"},
 {type: "", sound: "mkt_seller_e02.wav"},
 {type: "", sound: "musician_e01.wav"},
 {type: "", sound: "musician_g01.wav"},
 {type: "", sound: "musician_g02.wav"},
 {type: "", sound: "musician_g03.wav"},
 {type: "", sound: "musician_g04.wav"},
 {type: "", sound: "musician_g05.wav"},
 {type: "", sound: "musician_g06.wav"},
 {type: "", sound: "musician_g07.wav"},
 {type: "", sound: "musician_g08.wav"},
 {type: "", sound: "musician_g09.wav"},
 {type: "", sound: "musician_g10.wav"},
 {type: "", sound: "pharaoh_e01.wav"},
 {type: "", sound: "police_e01.WAV"},
 {type: "", sound: "police_e02.WAV"},
 {type: "", sound: "police_e03.WAV"},
 {type: "", sound: "police_e04.WAV"},
 {type: "", sound: "police_e05.WAV"},
 {type: "", sound: "police_e06.WAV"},
 {type: "", sound: "police_e07.WAV"},
 {type: "", sound: "police_e08.WAV"},
 {type: "", sound: "police_g01.WAV"},
 {type: "", sound: "police_g02.WAV"},
 {type: "", sound: "police_g03.WAV"},
 {type: "", sound: "police_g04.WAV"},
 {type: "", sound: "police_g05.WAV"},
 {type: "", sound: "police_g06.wav"},
 {type: "", sound: "police_g07.WAV"},
 {type: "", sound: "police_g08.WAV"},
 {type: "", sound: "police_g09.WAV"},
 {type: "", sound: "police_g10.WAV"},
 {type: "", sound: "priest_bast_e01.wav"},
 {type: "", sound: "priest_bast_e02.wav"},
 {type: "", sound: "priest_bast_e03.wav"},
 {type: "", sound: "priest_bast_e04.wav"},
 {type: "", sound: "priest_bast_g01.wav"},
 {type: "", sound: "priest_bast_g02.wav"},
 {type: "", sound: "priest_bast_g03.wav"},
 {type: "", sound: "priest_bast_g04.wav"},
 {type: "", sound: "priest_bast_g05.wav"},
 {type: "", sound: "priest_bast_g06.wav"},
 {type: "", sound: "priest_bast_g07.wav"},
 {type: "", sound: "priest_bast_g08.wav"},
 {type: "", sound: "priest_bast_g09.wav"},
 {type: "", sound: "priest_bast_g10.wav"},
 {type: "", sound: "priest_osiris_e01.wav"},
 {type: "", sound: "priest_osiris_e02.wav"},
 {type: "", sound: "priest_osiris_g01.wav"},
 {type: "", sound: "priest_osiris_g02.wav"},
 {type: "", sound: "priest_osiris_g03.wav"},
 {type: "", sound: "priest_osiris_g04.wav"},
 {type: "", sound: "priest_osiris_g05.wav"},
 {type: "", sound: "priest_osiris_g06.wav"},
 {type: "", sound: "priest_osiris_g07.wav"},
 {type: "", sound: "priest_osiris_g08.wav"},
 {type: "", sound: "priest_osiris_g09.wav"},
 {type: "", sound: "priest_osiris_g10.wav"},
 {type: "", sound: "priest_ptah_09.wav"},
 {type: "", sound: "priest_ptah_e01.wav"},
 {type: "", sound: "priest_ptah_e02.wav"},
 {type: "", sound: "priest_ptah_g01.wav"},
 {type: "", sound: "priest_ptah_g02.wav"},
 {type: "", sound: "priest_ptah_g03.wav"},
 {type: "", sound: "priest_ptah_g04.wav"},
 {type: "", sound: "priest_ptah_g05.wav"},
 {type: "", sound: "priest_ptah_g06.wav"},
 {type: "", sound: "priest_ptah_g07.wav"},
 {type: "", sound: "priest_ptah_g08.wav"},
 {type: "", sound: "priest_ptah_g10.wav"},
 {type: "", sound: "priest_ra_e01.wav"},
 {type: "", sound: "priest_ra_e02.wav"},
 {type: "", sound: "priest_ra_g01.wav"},
 {type: "", sound: "priest_ra_g02.wav"},
 {type: "", sound: "priest_ra_g03.wav"},
 {type: "", sound: "priest_ra_g04.wav"},
 {type: "", sound: "priest_ra_g05.wav"},
 {type: "", sound: "priest_ra_g06.wav"},
 {type: "", sound: "priest_ra_g07.wav"},
 {type: "", sound: "priest_ra_g08.wav"},
 {type: "", sound: "priest_ra_g09.wav"},
 {type: "", sound: "priest_ra_g10.wav"},
 {type: "", sound: "priest_seth_e01.wav"},
 {type: "", sound: "priest_seth_e02.wav"},
 {type: "", sound: "priest_seth_g01.wav"},
 {type: "", sound: "priest_seth_g02.wav"},
 {type: "", sound: "priest_seth_g03.wav"},
 {type: "", sound: "priest_seth_g04.wav"},
 {type: "", sound: "priest_seth_g05.wav"},
 {type: "", sound: "priest_seth_g06.wav"},
 {type: "", sound: "priest_seth_g07.wav"},
 {type: "", sound: "priest_seth_g08.wav"},
 {type: "", sound: "priest_seth_g09.wav"},
 {type: "", sound: "priest_seth_g10.wav"},
 {type: "", sound: "Reed_e01.wav"},
 {type: "", sound: "Reed_e02.wav"},
 {type: "", sound: "robber_e01.wav"},
 {type: "", sound: "robber_e02.wav"},
 {type: "", sound: "scribe_e01.wav"},
 {type: "", sound: "scribe_g01.wav"},
 {type: "", sound: "scribe_g02.wav"},
 {type: "", sound: "scribe_g03.wav"},
 {type: "", sound: "scribe_g04.wav"},
 {type: "", sound: "scribe_g05.wav"},
 {type: "", sound: "scribe_g06.wav"},
 {type: "", sound: "scribe_g07.wav"},
 {type: "", sound: "scribe_g08.wav"},
 {type: "", sound: "scribe_g09.wav"},
 {type: "", sound: "scribe_g10.wav"},
 {type: "", sound: "senet_e01.wav"},
 {type: "", sound: "senet_g01.wav"},
 {type: "", sound: "senet_g02.wav"},
 {type: "", sound: "senet_g03.wav"},
 {type: "", sound: "senet_g04.wav"},
 {type: "", sound: "senet_g05.wav"},
 {type: "", sound: "senet_g06.wav"},
 {type: "", sound: "senet_g07.wav"},
 {type: "", sound: "senet_g08.wav"},
 {type: "", sound: "senet_g09.wav"},
 {type: "", sound: "senet_g10.wav"},
 {type: "", sound: "stone_e01.wav"},
 {type: "", sound: "stone_e02.wav"},
 {type: "", sound: "taxman_e01.wav"},
 {type: "", sound: "taxman_e02.wav"},
 {type: "", sound: "taxman_e03.wav"},
 {type: "", sound: "taxman_g01.wav"},
 {type: "", sound: "taxman_g02.wav"},
 {type: "", sound: "taxman_g03.wav"},
 {type: "", sound: "taxman_g04.wav"},
 {type: "", sound: "taxman_g05.wav"},
 {type: "", sound: "taxman_g06.wav"},
 {type: "", sound: "taxman_g07.wav"},
 {type: "", sound: "taxman_g08.wav"},
 {type: "", sound: "taxman_g09.wav"},
 {type: "", sound: "taxman_g10.wav"},
 {type: "", sound: "teacher_e01.wav"},
 {type: "", sound: "teacher_g01.wav"},
 {type: "", sound: "teacher_g02.wav"},
 {type: "", sound: "teacher_g03.wav"},
 {type: "", sound: "teacher_g04.wav"},
 {type: "", sound: "teacher_g05.wav"},
 {type: "", sound: "teacher_g06.wav"},
 {type: "", sound: "teacher_g07.wav"},
 {type: "", sound: "teacher_g08.wav"},
 {type: "", sound: "teacher_g09.wav"},
 {type: "", sound: "teacher_g10.wav"},
 {type: "", sound: "thief_e01.wav"},
 {type: "", sound: "thief_e02.wav"},
 {type: "", sound: "thief_e03.wav"},
 {type: "", sound: "thief_e04.wav"},
 {type: "", sound: "transport_e01.wav"},
 {type: "", sound: "transport_e02.wav"},
 {type: "", sound: "transport_e03.wav"},
 {type: "", sound: "transport_e04.wav"},
 {type: "", sound: "vagrant_e01.wav"},
 {type: "", sound: "vagrant_e02.wav"},
 {type: "", sound: "warship_e01.wav"},
 {type: "", sound: "warship_e02.wav"},
 {type: "", sound: "warship_e03.wav"},
 {type: "", sound: "warship_e04.wav"},
 {type: "", sound: "warship_e05.wav"},
 {type: "", sound: "water_g01.wav"},
 {type: "", sound: "water_g02.wav"},
 {type: "", sound: "water_g03.wav"},
 {type: "", sound: "water_g04.wav"},
 {type: "", sound: "water_g05.wav"},
 {type: "", sound: "water_g06.wav"},
 {type: "", sound: "water_g07.wav"},
 {type: "", sound: "water_g08.wav"},
 {type: "", sound: "water_g09.wav"},
 {type: "", sound: "water_g10.wav"},
 {type: "", sound: "woodcutter_e01.wav"},
 {type: "", sound: "woodcutter_e02.wav"},
 {type: "", sound: "worker_e02.wav"},
 {type: "", sound: "worker_e03.wav"},
 {type: "", sound: "worker_g01.wav"},
 {type: "", sound: "worker_g02.wav"},
 {type: "", sound: "worker_g03.wav"},
 {type: "", sound: "worker_g04.wav"},
 {type: "", sound: "worker_g05.wav"},
 {type: "", sound: "worker_g06.wav"},
 {type: "", sound: "worker_g07.wav"},
 {type: "", sound: "worker_g08.wav"},
 {type: "", sound: "worker_g09.wav"},
 {type: "", sound: "worker_g10.wav"},
 {type: "", sound: "zookeeper_e01.wav"},
 {type: "", sound: "zookeeper_e02.wav"},
 {type: "", sound: "zookeeper_e03.wav"},
 {type: "", sound: "zookeeper_e04.wav"},
 {type: "", sound: "zookeeper_e05.wav"},
 {type: "", sound: "zookeeper_e06.wav"},
 {type: "", sound: "zookeeper_e07.wav"},
 {type: "", sound: "zookeeper_e08.wav"},
 {type: "", sound: "zookeeper_e09.wav"},
 {type: "", sound: "zookeeper_e10.wav"}
]
