#######################################################################
Codes
#######################################################################

::

    main.cc -> main -> init_config()
                    -> functions -> test_extrema() -> raw_extrema, keypoint
                                 -> test_orientation()
                                 -> test_match()
                                 -> test_inlier()
                                 -> test_wrap()
                                 -> planet()
                                 -> work() -------------------------->



    stitch.cc -> build() -> calc_feature()
                         -> pairwise_matches()
                         -> free_feature()
                         -> draw_matchinfo() / dump_matchinfo()
                         -> assign_center()
                         -> estimate_camera() / build_linear_simple()
                         -> pairwise_matches()
                         -> bundle()  ---------------------->

    stitch_images.cc -> ConnectedImages() -> blend()  ------------------->

    multiband.cc -> add_images()
                 -> run() -> create_first_level()
                          -> update_weight_map()
                          -> target
                          -> create_next_level()

::
    
    CylinderStitcher <- StitcherBase


::

    1. calc_feature()
    2. build_warp()
    3. free_feature()
    4. bundle(): proj_method -> update_proj_range() -> ret
    5. perspective_correction()
