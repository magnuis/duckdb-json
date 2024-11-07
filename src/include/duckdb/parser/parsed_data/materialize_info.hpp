//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/parsed_data/materialize_info.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/parsed_data/parse_info.hpp"
#include "duckdb/parser/column_definition.hpp"
#include "duckdb/parser/tableref/basetableref.hpp"
#include "duckdb/parser/tableref.hpp"

namespace duckdb {

	struct MaterializeInfo : public ParseInfo {
		public:
			static constexpr const ParseInfoType TYPE = ParseInfoType::MATERIALIZE_INFO;

		public:
			MaterializeInfo();
			MaterializeInfo(const MaterializeInfo &info);

			string data_column;
			unique_ptr<ColumnDefinition> field_name;
			unique_ptr<TableRef> table_name;

		public:
			virtual unique_ptr<MaterializeInfo> Copy() const;
			string ToString() const;

			// void Serialize(Serializer &serializer) const override;
			// static unique_ptr<ParseInfo> Deserialize(Deserializer &deserializer);
	};
} // namespace duckdb
