#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>

class MedicalRecord {
private:
    std::string fullName;
    std::string dateOfBirth;
    std::string phoneNumber;
    std::string diseases;
    std::string vaccinations;

public:
    MedicalRecord(const std::string& name, const std::string& dob, const std::string& phone, const std::string& dis, const std::string& vacc)
        : fullName(name), dateOfBirth(dob), phoneNumber(phone), diseases(dis), vaccinations(vacc) {}

    std::string getFullName() const { return fullName; }
    void setFullName(const std::string& name) { fullName = name; }

    std::string getDateOfBirth() const { return dateOfBirth; }
    void setDateOfBirth(const std::string& dob) { dateOfBirth = dob; }

    std::string getPhoneNumber() const { return phoneNumber; }
    void setPhoneNumber(const std::string& phone) { phoneNumber = phone; }

    std::string getDiseases() const { return diseases; }
    void setDiseases(const std::string& dis) { diseases = dis; }

    std::string getVaccinations() const { return vaccinations; }
    void setVaccinations(const std::string& vacc) { vaccinations = vacc; }
};

void createMedicalRecord(std::ofstream& file);
bool isValidDateFormat(const std::string& date);
bool validateAndSavePatientRecord(std::ofstream& file, const std::string& fullName, const std::string& dateOfBirth, const std::string& phoneNumber, const std::string& diseases, const std::string& vaccinations);
void searchMedicalRecord(const std::string& name, const std::string& dateOfBirth, std::ifstream& file);
void showAllMedicalRecords(std::ifstream& file);

int main() {
    std::ofstream outFile("medical_records.txt", std::ios::app);
    
    char choice;
    std::string searchName;
    
    do {
        std::cout << "\nMain Menu:" << std::endl;
        std::cout << "1. Search for a patient by surname" << std::endl;
        std::cout << "2. Show all patients" << std::endl;
        std::cout << "3. Add a patient" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        try {
            std::ifstream inFile("medical_records.txt");
            if (!inFile.is_open() && choice != '4') {
                throw std::runtime_error("Error opening file.");
            }
            
            switch (choice) {
                case '1':
                    std::cout << "Enter surname to search for: ";
                    std::getline(std::cin >> std::ws, searchName);
                    searchMedicalRecord(searchName, "", inFile);
                    break;
                case '2':
                    showAllMedicalRecords(inFile);
                    break;
                case '3':
                    outFile.open("medical_records.txt", std::ios::app);
                    if (!outFile.is_open()) {
                        throw std::runtime_error("Error opening file.");
                    }
                    createMedicalRecord(outFile);
                    outFile.close();
                    break;
                case '4':
                    std::cout << "Exiting program." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please enter again." << std::endl;
            }
            
            inFile.close();
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    } 
    while (choice != '4');
    
    return 0;
}

bool validateAndSavePatientRecord(std::ofstream& file, const std::string& fullName, const std::string& dateOfBirth, const std::string& phoneNumber, const std::string& diseases, const std::string& vaccinations) {
    if (!isValidDateFormat(dateOfBirth)) {
        std::cout << "Invalid date format. Please enter date of birth again (format: DD.MM.YYYY)." << std::endl;
        return false;
    }

    file << fullName << "*" << dateOfBirth << "*" << phoneNumber << "*" << diseases << "*" << vaccinations << std::endl;
    std::cout << "Patient record saved successfully." << std::endl;
    return true;
}

void createMedicalRecord(std::ofstream& file) {
    std::string fullName, dateOfBirth, phoneNumber, diseases, vaccinations;
    char choice;
    
    do {
        std::cout << "Enter patient's full name: ";
        std::getline(std::cin >> std::ws, fullName);
        
        bool isValidDate = false;
        do {
            std::cout << "Enter patient's date of birth (format: DD.MM.YYYY): ";
            std::getline(std::cin >> std::ws, dateOfBirth);
            isValidDate = isValidDateFormat(dateOfBirth);
            if (!isValidDate) {
                std::cout << "Invalid date format. Please enter date of birth again (format: DD.MM.YYYY)." << std::endl;
            }
        } while (!isValidDate);

        if (!isValidDate) {
            continue;
        }

        std::cout << "Enter patient's phone number: ";
        std::getline(std::cin >> std::ws, phoneNumber);
        
        std::cout << "Enter patient's diseases: ";
        std::getline(std::cin >> std::ws, diseases);
        
        std::cout << "Enter patient's vaccinations: ";
        std::getline(std::cin >> std::ws, vaccinations);
        
        std::cout << "\nPatient record details:" << std::endl;
        std::cout << "Full Name: " << fullName << std::endl;
        std::cout << "Date of Birth: " << dateOfBirth << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "Diseases: " << diseases << std::endl;
        std::cout << "Vaccinations: " << vaccinations << std::endl;
        
        std::cout << "\nSave this patient record? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (std::tolower(choice) == 'y') {
            if (validateAndSavePatientRecord(file, fullName, dateOfBirth, phoneNumber, diseases, vaccinations)) {
                std::cout << "Patient record saved successfully." << std::endl;
            } else {
                std::cout << "Failed to save patient record." << std::endl;
            }
        } else {
            std::cout << "Patient record not saved." << std::endl;
        }
        
        std::cout << "\nDo you want to add another patient? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (std::tolower(choice) == 'y');
}

bool isValidDateFormat(const std::string& date) {


    int day, month, year;
    char delimiter; 

    std::istringstream ss(date); 
    ss >> day >> delimiter >> month >> delimiter >> year;

    if (ss.fail() || ss.eof() == false || delimiter != '.' || day < 1 || month < 1 || year < 0) {
        return false;
    }

    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31)) {
        return false;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30)) {
        return false;
    } else if (month == 2) {
        bool leapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
        if ((leapYear && day > 29) || (!leapYear && day > 28)) {
            return false;
        }
    }
    return true;
}

void searchMedicalRecord(const std::string& name, const std::string& dateOfBirth, std::ifstream& file) {
    std::string line;
    bool found = false;

    // Проверяем, существует ли уже запись для данного пациента
    while (std::getline(file, line)) {
        size_t namePos = line.find(name);
        size_t dobPos = line.find(dateOfBirth);
        if (namePos != std::string::npos && dobPos != std::string::npos) {
            found = true;
            std::cout << "Medical record already exists for this patient." << std::endl;
            break;
        }
    }

    // Если запись не найдена, выводим сообщение об отсутствии
    if (!found) {
        std::cout << "Medical record not found." << std::endl;
    }
}

void showAllMedicalRecords(std::ifstream& file) {
    std::string line;
    std::cout << "All medical records:" << std::endl;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string fullName, dateOfBirth, phoneNumber, diseases, vaccinations;
        std::getline(std::getline(std::getline(std::getline(iss, fullName, '*'), dateOfBirth, '*'), phoneNumber, '*'), diseases, '*');
        std::getline(iss, vaccinations);

        std::cout << "Patient's full name: " << fullName << std::endl;
        std::cout << "Patient's date of birth: " << dateOfBirth << std::endl;
        std::cout << "Patient's phone number: " << phoneNumber << std::endl;
        std::cout << "Patient's diseases: " << diseases << std::endl;
        std::cout << "Patient's vaccinations: " << vaccinations << std::endl;
        std::cout << "****************************************************" << std::endl;
    }
}
