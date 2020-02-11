#include "AppointmentsData.hpp"

AppointmentsData::AppointmentsData()
{
    this->_data = std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>>* AppointmentsData::getData()
{
    return &this->_data;
}

void AppointmentsData::setData(std::vector<std::vector<std::string>> data)
{
    this->_data = data;
}
