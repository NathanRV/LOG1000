#include "Appointments.hpp"

Appointments::Appointments(std::string filePath) : _csvHandler(CSVHandler(filePath))
{
    this->_headers = this->_csvHandler.getHeader(); // It is correct to return vector<T> as lvalue.
    this->setData(this->_csvHandler.getData());
}

std::vector<unsigned int> Appointments::fillDisplayColumns(std::vector<unsigned int> displayedColumns){
    if(displayedColumns.empty()){
        displayedColumns = std::vector<unsigned int>(this->_headers.size());
        std::iota(displayedColumns.begin(), displayedColumns.end(), 0);
    }
    return displayedColumns;
}

void Appointments::displayHeaders(std::vector<unsigned int> displayedColumns){
    for (unsigned int col : displayedColumns)
    {
        std::cout << std::setw(this->_COLUMN_WIDTH)
                  << this->_headers[col];
    }
    std::cout << std::endl
              << std::string(displayedColumns.size() * this->_COLUMN_WIDTH, '_')
              << std::endl;
}

std::vector<std::vector<std::string>> Appointments::filterAppointments(unsigned int userCol, std::string userId, std::vector<std::vector<std::string>> filteredAppointments){
    std::copy_if(
        this->getData()->begin(),
        this->getData()->end(),
        std::back_inserter(filteredAppointments),
            [userId, userCol](std::vector<std::string> appointment) {
                return appointment[userCol] == userId;
            });
    return filteredAppointments;
}

void Appointments::displayAppointments(std::vector<std::vector<std::string>> filteredAppointments, unsigned int appointmentIdx, std::vector<unsigned int> displayedColumns){
    for (std::vector<std::string> filteredAppointment : filteredAppointments)
    {
        std::cout << appointmentIdx++
                  << '.' 
                  << std::setw(this->_COLUMN_WIDTH - 2);

        for (unsigned int col : displayedColumns)
        {
            std::cout << filteredAppointment[col].substr(0, this->_COLUMN_WIDTH - 1)
                      << std::setw(this->_COLUMN_WIDTH);
        }

        std::cout << '\n';
    }
}

void Appointments::display(unsigned int userCol, std::string userId, std::vector<unsigned int> displayedColumns)
{
    std::vector<std::vector<std::string>> filteredAppointments;
    unsigned int appointmentIdx = 1;

    displayedColumns=fillDisplayColumns(displayedColumns);
    displayHeaders(displayedColumns);
    filteredAppointments=filterAppointments(userCol, userId, filteredAppointments);
    displayAppointments(filteredAppointments, appointmentIdx, displayedColumns);    
}

bool Appointments::schedule(std::string patientId, std::string nurseId)
{
    std::vector<std::string> newAppointment = this->createNewAppointment(patientId, nurseId);

    for (std::vector<std::string> appointment : *(this->getData()))
    {
        bool isOccupied = newAppointment[APPOINTMENT_DATE] == appointment[APPOINTMENT_DATE] &&
                          newAppointment[APPOINTMENT_TIME] == appointment[APPOINTMENT_TIME];
        if (isOccupied)
        {
            return false; // Schedule did not work
        }
    }
    // Update appointment list and file.
    this->getData()->push_back(newAppointment);
    this->_csvHandler.writeData(newAppointment);
    return true;
}

std::vector<std::vector<std::string>>* Appointments::getData()
{
    return &_appointmentsData;
}

void Appointments::setData(std::vector<std::vector<std::string>> data)
{
    this->_appointmentsData=data;
}

std::vector<std::string> Appointments::createNewAppointment(std::string patientId, std::string nurseId)
{
    std::vector<std::string> newAppointment(this->_headers.size());
    newAppointment[APPOINTMENT_NURSE_ID] = nurseId;
    newAppointment[APPOINTMENT_PATIENT_ID] = patientId;

    std::cout << "\nVeuillez indiquer la date du rendez-vous [jj/mm/aaaa]: ";
    std::cin >> newAppointment[APPOINTMENT_DATE];

    std::cout << "\nVeuillez indiquer le moment du rendez-vous [AM/PM]: ";
    std::cin >> newAppointment[APPOINTMENT_TIME];

    std::cout << "\nVeuillez indiquer la raison du rendez-vous: ";
    std::cin >> newAppointment[APPOINTMENT_REASON];

    return newAppointment;
}