#include "duckdb/parser/parsed_data/materialize_info.hpp"
#include "duckdb/parser/tableref/basetableref.hpp"

namespace duckdb {

MaterializeInfo::MaterializeInfo() : ParseInfo(TYPE) {
}

MaterializeInfo::MaterializeInfo(const MaterializeInfo &info)
    : ParseInfo(info.info_type), data_column(info.data_column), field_name(make_uniq<ColumnDefinition>(info.field_name->GetName(), info.field_name->GetType())), table_name(info.table_name ? info.table_name->Copy() : nullptr) {
}

unique_ptr<MaterializeInfo> MaterializeInfo::Copy() const {
	return make_uniq<MaterializeInfo>(*this);
}

string MaterializeInfo::ToString() const {
    string result = "MATERIALIZE ";

    // result += data_column + " ";
    // result += field_name + " ";
	// TODOHM
    // result += "FROM " + table_name;
    result += ";";
    return result;
}



} // namespace duckdb
