#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

#include "Constants.hpp"
#include "CSVHandler.hpp"
#include "AppointmentsData.hpp"

class Appointments
{
public:
    Appointments(std::string filePath);
    void display(unsigned int userCol, std::string userId, std::vector<unsigned int> displayedColumns = {});
    bool schedule(std::string patientId, std::string nurseId);

private:
    std::vector<std::string> createNewAppointment(std::string patientId, std::string nurseId);

    AppointmentsData _appointmentsData;
    std::vector<std::string> _headers;
    CSVHandler _csvHandler;

    const unsigned int _COLUMN_WIDTH = 14;
};
