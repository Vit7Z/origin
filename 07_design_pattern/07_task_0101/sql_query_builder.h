#pragma once
#include <iostream>
#include <vector>
#include <map>

class SqlSelectQueryBuilder
{
public:
	SqlSelectQueryBuilder& AddColumn(std::string column_name);
	SqlSelectQueryBuilder& AddFrom(std::string table_name);
	SqlSelectQueryBuilder& AddWhere(std::string column_name, std::string value);
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv);
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns);
	std::string BuildQuery();

protected:
	std::string columnNames = "*";
	bool columnNamesIsEmpty = true;

	std::string tableName = "";

	std::string whereCondition = "";
	bool whereConditionIsOne = true;

	std::string buildQuery = "\"SELECT";
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder
{
public:
	using SqlSelectQueryBuilder::AddColumn;
	using SqlSelectQueryBuilder::AddFrom;
	using SqlSelectQueryBuilder::AddWhere;
	using SqlSelectQueryBuilder::AddColumns;
	AdvancedSqlSelectQueryBuilder& AddWhere(std::string column_name, std::string m_operator, std::string value);
};