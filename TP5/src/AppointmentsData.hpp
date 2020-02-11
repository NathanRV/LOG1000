#pragma once

#include <vector>
#include <string>

class AppointmentsData
{
public:
    AppointmentsData();
    std::vector<std::vector<std::string>>* getData();
    void setData(std::vector<std::vector<std::string>> data);

private:
    std::vector<std::vector<std::string>> _data;
};
