#ifndef DBMS_DATA_TYPES_NUMBER_FIXED_H
#define DBMS_DATA_TYPES_NUMBER_FIXED_H

#include <DB/Columns/ColumnsNumber.h>
#include <DB/DataTypes/IDataTypeNumberFixed.h>


namespace DB
{

/** Типы столбцов для чисел фиксированной ширины. */

#define DEFINE_DATA_TYPE_NUMBER_FIXED(TYPE) 										\
	class DataType ## TYPE : public IDataTypeNumberFixed<TYPE, Column ## TYPE>		\
	{																				\
	public:																			\
		std::string getName() const { return #TYPE; }								\
		SharedPtr<IDataType> clone() const { return new DataType ## TYPE; }			\
	};

DEFINE_DATA_TYPE_NUMBER_FIXED(UInt8);
DEFINE_DATA_TYPE_NUMBER_FIXED(UInt16);
DEFINE_DATA_TYPE_NUMBER_FIXED(UInt32);
DEFINE_DATA_TYPE_NUMBER_FIXED(UInt64);

DEFINE_DATA_TYPE_NUMBER_FIXED(Int8);
DEFINE_DATA_TYPE_NUMBER_FIXED(Int16);
DEFINE_DATA_TYPE_NUMBER_FIXED(Int32);
DEFINE_DATA_TYPE_NUMBER_FIXED(Int64);

/* DEFINE_DATA_TYPE_NUMBER_FIXED(Float32);
DEFINE_DATA_TYPE_NUMBER_FIXED(Float64); */

}

#endif
