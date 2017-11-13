##############################################################################
Algorithms
##############################################################################

features
==============================================================================

- feats <Descriptor>
- keypoints <SSPoint>: SIFT

feats <Descriptor>:

::

    Vec2D coor
    std::vector<float> descriptor
    float euclidean_sqr()
    int hamming()


keypoints <SSPoint>: scale-space point

::

    Coor coor             // integer coordinate in the pyramid
    Vec2D real_coor       // scaled [0, 1) coordinate in the original image
    int pyr_id            // pyramid id
    int scale_id          // scale id
    float dir
    float scale_factor


bundle <ConnectedImages>:

::

    Range {
        Vec2D min
        Vec2D max
        Vec2D size()
    }

    ProjectionMethod: flat, cylindrical, spherical
    
    identity_idx

    ImageComponent {
        Homography homo
        Homography homo_inv
        ImageRef * imgptr
        Range range
    }

    shift_all_homo()
    calc_inverse_homo()
    blend()
    get_final_resolution()


image blending
==============================================================================

- multiband blending
- feather blending
- alpha blending
- laplacian blending


::

    BlenderBase -> LinearBlender
                -> MultiBandBlender


    BlenderBase

        Range {
            Coor min
            Coor max
            contain()
            width()
            height()
        }

        ImageToAdd {
            Range range
            ImageRef & imgref
            std::function(Vec2D(Coor)) coor_func
            Vec2D map_coor()
        }

        add_image()
        run()


    LinearBlender

    MultiBandBlender

        WeightedPixel {
            Color c
            float w
        }

        Mask2D {
            get()
            set()
            Mask2D(w, mask)
        }

        MetaImage {
            Range range
            Mask2D mask
        }

        ImageToBlend {
            Mat<WeightedPixel> img
            MetaImage meta
            float weight_on_target()
            float & weight_on_target()
            Color & color_on_target()
            bool valid_on_target()
        }

        std::vector<ImageToAdd> images_to_add
        std::vector<MetaImage> meta_images
        std::vector<ImageToBlend> images
        std::vector<ImageToBlend> next_lvl_images

        create_first_level()
        update_weight_map()
        create_next_level()
        debug_level()

        Coor target_size{0, 0}
        int band_level
