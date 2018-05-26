#ifndef GENERATE_PROPOSAL_LABELS_SINGLE_IMAGE_OP_H_
#define GENERATE_PROPOSAL_LABELS_SINGLE_IMAGE_OP_H_

#include "caffe2/core/context.h"
#include "caffe2/core/operator.h"

namespace caffe2 {

template <typename T, class Context>
class GenerateProposalLabelsSingleImageOp final : public Operator<Context> {
 public:
  GenerateProposalLabelsSingleImageOp(const OperatorDef& def, Workspace* ws)
      : Operator<Context>(def, ws),
        rois_per_image_(OperatorBase::GetSingleArgument<int>("rois_per_image", 64)),
        fg_rois_per_image_(OperatorBase::GetSingleArgument<int>("fg_rois_per_image", 16)),
        fg_thresh_(OperatorBase::GetSingleArgument<float>("fg_thresh", 0.5)),
        bg_thresh_hi_(OperatorBase::GetSingleArgument<float>("bg_thresh_hi", 0.5)), {
        bg_thresh_lo_(OperatorBase::GetSingleArgument<float>("bg_thresh_lo", 0.0)),
        im_(OperatorBase::GetSingleArgument<int>("im", 0)) {
    DCHECK_GT(rois_per_image_, 0);
    DCHECK_GT(fg_rois_per_image_, 0);
    DCHECK_GE(fg_thresh_, 0.);
    DCHECK_LE(fg_thresh_, 1.);
    DCHECK_GE(bg_thresh_hi_, 0.)
    DCHECK_LE(bg_thresh_hi_, 1.)
    DCHECK_GE(bg_thresh_lo_, 0.)
    DCHECK_LE(bg_thresh_lo_, 1.)
    DCHECK_GT(im_, 0);
  }
  USE_OPERATOR_CONTEXT_FUNCTIONS;

  bool RunOnDevice() override;

 protected:
  int rois_per_image_;
  int fg_rois_per_image_;
  float fg_thresh_;
  float bg_thresh_hi_;
  float bg_thresh_lo_;
  int im_;

  // Tensor<Context> Yv;
  // Tensor<Context> Yi;
  // Tensor<Context> rois_raw;
};

} // namespace caffe2

#endif // GENERATE_PROPOSAL_LABELS_SINGLE_IMAGE_OP_H_
