#ifndef __DATA_TYPE_H__
#define __DATA_TYPE_H__
void DataType()
{
	get();
	if (isdatatype(tkn->lexeme) == 0)
	{
		failure("Data Type Expected! : Data_Type.");
	}
}
#endif