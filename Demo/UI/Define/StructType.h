#ifndef STRUCTTYPE_H
#define STRUCTTYPE_H
#include "EnumType.h"
#include <QString>

/**
 * @brief 导入DXF需要的数据
*/
struct ImportDxfData 
{
	ImportDxfData()
	{
		clear();
	}
	void clear()
	{
		loadType_ = ProjectLoadType::LT_Open;
		scaleType_.clear(); //scale 类型
		scalePercent_ = 100.00;
		rotateType_ = RotateDirection::RD_No;
		//optionMap_.clear();
		bPatternAnnotation_ = false;
		bAutoTrace_ = false;
		bSwapCutAndSewLine_ = true;
		bIncludeNotches_ = true;
		bAutoDistribute_ = false;
		bOptimizeAllCurvePoints_ = false;
		bDrawCurvePoints_ = false;
	}
	ProjectLoadType loadType_; //数据加载类型
	QString scaleType_; //scale 类型
	double scalePercent_; //scale 百分比
	RotateDirection rotateType_; //旋转类型

	//QMap<QString, bool> optionMap_; //各选项集合

	bool bPatternAnnotation_;  //Pattern Annotation
	bool bAutoTrace_;//Auto-Trace as Internal Lines
	bool bSwapCutAndSewLine_; 
	bool bIncludeNotches_;
	bool bAutoDistribute_;
	bool bOptimizeAllCurvePoints_;
	bool bDrawCurvePoints_;
};

/**
 * @brief 导出DXF需要的数据
*/
struct ExportDxfData
{
	ExportDxfData()
	{
		clear();
	}
	void clear()
	{
		dxfFormatType_.clear();
		scaleType_.clear(); //scale 类型
		scalePercent_ = 100.00;
		rotateType_ = RotateDirection::RD_No;
		bWithoutGrading_ = false;
		bWithoutBaselines_ = false;
		bDuplicateNotchOnSeam_ = true;
		bSwapCutAndSewLine_ = true;
		bConverCurvePointToStraightPoint_ = false;
		bOptimizeAllCurvePoints_ = false;
		bPatternBoundingBox_ = false;
		bSingleBoundBox_ = false;
		bSeparateBoundBox_ = false;
	}
	QString dxfFormatType_; //DXF格式类型
	QString scaleType_; //scale 类型
	double scalePercent_; //scale 百分比
	RotateDirection rotateType_; //旋转类型

	bool bWithoutGrading_;  
	bool bWithoutBaselines_;
	bool bDuplicateNotchOnSeam_;
	bool bSwapCutAndSewLine_;
	bool bConverCurvePointToStraightPoint_;
	bool bOptimizeAllCurvePoints_;
	bool bPatternBoundingBox_;
	bool bSingleBoundBox_;
	bool bSeparateBoundBox_;
};

#endif // STRUCTTYPE_H
