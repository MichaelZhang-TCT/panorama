Computer Vision: algorithms and applications 
(link: http://szeliski.org/Book/drafts/SzeliskiBook_20100903_draft.pdf)

SIFT (p224)

Scale invariant feature transform (SIFT). SIFT features are formed by computing the
gradient at each pixel in a 16×16 window around the detected keypoint, using the appropriate
level of the Gaussian pyramid at which the keypoint was detected. The gradient magnitudes
are downweighted by a Gaussian fall-off function (shown as a blue circle in (Figure 4.18a) in
order to reduce the influence of gradients far from the center, as these are more affected by
small misregistrations.
In each 4 × 4 quadrant, a gradient orientation histogram is formed by (conceptually)
adding the weighted gradient value to one of eight orientation histogram bins. To reduce the
effects of location and dominant orientation misestimation, each of the original 256 weighted
gradient magnitudes is softly added to 2 × 2 × 2 histogram bins using trilinear interpolation.
Softly distributing values to adjacent histogram bins is generally a good idea in any application
where histograms are being computed, e.g., for Hough transforms (Section 4.3.2) or
local histogram equalization (Section 3.1.4).
The resulting 128 non-negative values form a raw version of the SIFT descriptor vector.
To reduce the effects of contrast or gain (additive variations are already removed by the gradient),
the 128-D vector is normalized to unit length. To further make the descriptor robust to
other photometric variations, values are clipped to 0.2 and the resulting vector is once again
renormalized to unit length.
