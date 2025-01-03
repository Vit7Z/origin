#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string column_name) {
  if (columnNamesIsEmpty) {
    columnNames = column_name;
    columnNamesIsEmpty = false;
  }
  else {
    columnNames += ", " + column_name;
  }
  return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string table_name) {
  tableName = table_name;
  return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string column_name, std::string value) {
  if (whereConditionIsOne) {
    whereCondition += column_name + "=" + value;
    whereConditionIsOne = false;
  }
  else {
    whereCondition += " AND " + column_name + "=" + value;
  }
  return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) {
  for (const auto& el : kv) {
    if (whereConditionIsOne) {
      whereCondition += el.first + "=" + el.second;
      whereConditionIsOne = false;
    }
    else {
      whereCondition += " AND " + el.first + "=" + el.second;
    }
  }
  return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) {
  for (const auto& el : columns) {
    if (columnNamesIsEmpty) {
      columnNames = el;
      columnNamesIsEmpty = false;
    }
    else {
      columnNames += ", " + el;
    }
  }
  return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
  buildQuery = "SELECT";
  buildQuery += " " + columnNames + " FROM " + tableName + " WHERE " + whereCondition + ";";
  return buildQuery;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhere(std::string column_name, std::string m_operator, std::string value) {
  if (whereConditionIsOne) {
    whereCondition += column_name + m_operator + value;
    whereConditionIsOne = false;
  }
  else {
    whereCondition += " AND " + column_name + m_operator + value;
  }
  return *this;
}