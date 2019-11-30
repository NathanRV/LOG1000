#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

#include "Constants.hpp"
#include "CSVHandler.hpp"

class Appointments
{
public:
    Appointments(std::string filePath);
    void display(unsigned int userCol, std::string userId, std::vector<unsigned int> displayedColumns = {});
    bool schedule(std::string patientId, std::string nurseId);

    std::vector<unsigned int> fillDisplayColumns(std::vector<unsigned int> displayedColumns);
    void displayHeaders(std::vector<unsigned int> displayedColumns);
    std::vector<std::vector<std::string>> filterAppointments(unsigned int userCol, std::string userId, std::vector<std::vector<std::string>> filteredAppointments);
    void displayAppointments(std::vector<std::vector<std::string>> filteredAppointments, unsigned int appointmentIdx, std::vector<unsigned int> displayedColumns);

    std::vector<std::vector<std::string>>* getData();
    void setData(std::vector<std::vector<std::string>> data);
private:
    std::vector<std::string> createNewAppointment(std::string patientId, std::string nurseId);

    std::vector<std::vector<std::string>> _appointmentsData;
    std::vector<std::string> _headers;
    CSVHandler _csvHandler;

    const unsigned int _COLUMN_WIDTH = 14;
};
