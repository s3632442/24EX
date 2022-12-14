#include "DataHandler.h"

// Constructors
DataHandler::DataHandler()
{
    filename = nullptr;
    currentPlayerName = nullptr;
    bag = nullptr;
    board = nullptr;
    player1 = nullptr;
    player2 = nullptr;
}

// Destructor
DataHandler::~DataHandler()
{

    // TODO
}

// loads data from a file & assigns it to relevent variables
//  assumtion is that the input file is in a valid format
//  file needs to exist & able to be opened
bool DataHandler::loadData(std::string filename)
{

    this->filename = &filename;
    numToPlayLoaded = new char();
    currentPlayerName = new std::string("");
    bag = new LinkedList;
    board = new Register(26, 26);
    player1 = new Player();
    player2 = new Player();
    player3 = new Player();
    player4 = new Player();

    std::string line;
    std::vector<std::string> gameData;
    std::ifstream inputFile(filename);

    // read each line
    while (getline(inputFile, line))
    {
        gameData.push_back(line);
    }

    for (int i = 0; i < gameData.size(); i++)
    {
        if (i == 0)
        {

            setNumToPlay(gameData.at(i)[0]);
        }
        if (i == 1)
        {
            player1->setName(gameData.at(i));
        }
        if (i == 2)
        {
            player1->setScore(std::stoi(gameData.at(i)));
        }
        if (i == 3)
        {

            std::vector<std::string> PatientsInHandAsStrings;
            char *str = const_cast<char *>(gameData.at(i).c_str());

            // Returns first token
            char *token = strtok(str, ", ");

            // Keep printing tokens while one of the
            // delimiters present in str[].
            while (token != NULL)
            {
                PatientsInHandAsStrings.push_back(token);
                token = strtok(NULL, ", ");
            }

            int PatientCount = PatientsInHandAsStrings.size();
            LinkedList *player1_hand = player1->getHand();

            for (int i = 0; i < PatientCount; i++)
            {
                Ward ward = PatientsInHandAsStrings.at(i).at(0);
                Shape shape = int(PatientsInHandAsStrings.at(i).at(1) - '0');
                Patient *Patient = new Patient(ward, shape);
                player1_hand->addEnd(Patient);
            }
        }
        if (i == 4)
        {
            player2->setName(gameData.at(i));
        }
        if (i == 5)
        {
            player2->setScore(std::stoi(gameData.at(i)));
        }
        if (i == 6)
        {
            // To Do. Parse player2 hand
            std::vector<std::string> PatientsInHandAsStrings;
            char *str = const_cast<char *>(gameData.at(i).c_str());

            // Returns first token
            char *token = strtok(str, ", ");

            // Keep printing tokens while one of the
            // delimiters present in str[].
            while (token != NULL)
            {

                PatientsInHandAsStrings.push_back(token);

                token = strtok(NULL, ", ");
            }

            int PatientCount = PatientsInHandAsStrings.size();
            LinkedList *player2_hand = player2->getHand();

            for (int i = 0; i < PatientCount; i++)
            {
                Ward ward = PatientsInHandAsStrings.at(i).at(0);
                Shape shape = int(PatientsInHandAsStrings.at(i).at(1) - '0');
                Patient *Patient = new Patient(ward, shape);
                player2_hand->addEnd(Patient);
            }

            player2->setHand(player2_hand);
        }
        else if (getNumToPlayLoaded() == '3')
        {

            if (i == 7)
            {
                player3->setName(gameData.at(i));
            }
            if (i == 8)
            {
                player3->setScore(std::stoi(gameData.at(i)));
            }
            if (i == 9)
            {
                // To Do. Parse player2 hand
                std::vector<std::string> PatientsInHandAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {

                    PatientsInHandAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInHandAsStrings.size();
                LinkedList *player3_hand = player3->getHand();

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInHandAsStrings.at(i).at(0);
                    Shape shape = int(PatientsInHandAsStrings.at(i).at(1) - '0');
                    Patient *Patient = new Patient(ward, shape);
                    player3_hand->addEnd(Patient);
                }

                player3->setHand(player3_hand);
            }
            if (i == 10)
            {
                // To Do. Register height and width.
                board = new Register(getRegisterHeight(), getRegisterWidth());
            }
            if (i == 11)
            {
                std::vector<std::string> PatientsInHandAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {
                    PatientsInHandAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInHandAsStrings.size();
                LinkedList *player4_hand = player4->getHand();

                char row = 0;
                int col = 0;

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInHandAsStrings.at(i).at(0);
                    Shape shape = int(PatientsInHandAsStrings.at(i).at(1) - '0');

                    int row = PatientsInHandAsStrings.at(i).at(3) - ASCII_ALPHABET_OFFSET;

                    col = int(PatientsInHandAsStrings.at(i).at(4) - '0');
                    Patient *Patient = new Patient(ward, shape);
                    board->placePatientAt(Patient, row, col);
                }
            }
            if (i == 12)
            {
                // ToDo: bag.addEnd(everyParsedPatient)
                std::vector<std::string> PatientsInBagAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {
                    PatientsInBagAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInBagAsStrings.size();

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInBagAsStrings.at(i).at(0);
                    Shape shape = PatientsInBagAsStrings.at(i).at(1);
                    Patient *Patient = new Patient(ward, shape);
                    bag->addEnd(Patient);
                }
            }
            if (i == 13)
            {
                currentPlayerName = &gameData.at(i);
            }
        }
        else if (getNumToPlayLoaded() == '4')
        {

            if (i == 7)
            {
                player3->setName(gameData.at(i));
            }
            if (i == 8)
            {
                player3->setScore(std::stoi(gameData.at(i)));
            }
            if (i == 9)
            {
                // To Do. Parse player2 hand
                std::vector<std::string> PatientsInHandAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {

                    PatientsInHandAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInHandAsStrings.size();
                LinkedList *player3_hand = player3->getHand();

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInHandAsStrings.at(i).at(0);
                    Shape shape = int(PatientsInHandAsStrings.at(i).at(1) - '0');
                    Patient *Patient = new Patient(ward, shape);
                    player3_hand->addEnd(Patient);
                }

                player3->setHand(player3_hand);
            }

            if (i == 10)
            {
                player4->setName(gameData.at(i));
            }
            if (i == 11)
            {
                player4->setScore(std::stoi(gameData.at(i)));
            }
            if (i == 12)
            {
                // To Do. Parse player2 hand
                std::vector<std::string> PatientsInHandAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {

                    PatientsInHandAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInHandAsStrings.size();
                LinkedList *player4_hand = player4->getHand();

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInHandAsStrings.at(i).at(0);
                    Shape shape = int(PatientsInHandAsStrings.at(i).at(1) - '0');
                    Patient *Patient = new Patient(ward, shape);
                    player4_hand->addEnd(Patient);
                }

                player4->setHand(player4_hand);
            }
            if (i == 13)
            {
                // To Do. Register height and width.
                board = new Register(getRegisterHeight(), getRegisterWidth());
            }
            if (i == 14)
            {
                std::vector<std::string> PatientsInHandAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {
                    PatientsInHandAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInHandAsStrings.size();
                LinkedList *player4_hand = player4->getHand();

                char row = 0;
                int col = 0;

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInHandAsStrings.at(i).at(0);
                    Shape shape = int(PatientsInHandAsStrings.at(i).at(1) - '0');

                    int row = PatientsInHandAsStrings.at(i).at(3) - ASCII_ALPHABET_OFFSET;

                    col = int(PatientsInHandAsStrings.at(i).at(4) - '0');
                    Patient *Patient = new Patient(ward, shape);
                    board->placePatientAt(Patient, row, col);
                }
            }
            if (i == 15)
            {
                // ToDo: bag.addEnd(everyParsedPatient)
                std::vector<std::string> PatientsInBagAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {
                    PatientsInBagAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInBagAsStrings.size();

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInBagAsStrings.at(i).at(0);
                    Shape shape = PatientsInBagAsStrings.at(i).at(1);
                    Patient *Patient = new Patient(ward, shape);
                    bag->addEnd(Patient);
                }
            }
            if (i == 16)
            {
                currentPlayerName = &gameData.at(i);
            }
        }
        else
        {

            if (i == 7)
            {
                // To Do. Register height and width.
                board = new Register(getRegisterHeight(), getRegisterWidth());
            }
            if (i == 8)
            {
                std::vector<std::string> PatientsInHandAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {
                    PatientsInHandAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInHandAsStrings.size();
                LinkedList *player2_hand = player2->getHand();

                char row = 0;
                int col = 0;

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInHandAsStrings.at(i).at(0);
                    Shape shape = int(PatientsInHandAsStrings.at(i).at(1) - '0');

                    int row = PatientsInHandAsStrings.at(i).at(3) - ASCII_ALPHABET_OFFSET;

                    col = int(PatientsInHandAsStrings.at(i).at(4) - '0');
                    Patient *Patient = new Patient(ward, shape);
                    board->placePatientAt(Patient, row, col);
                }
            }
            if (i == 9)
            {
                // ToDo: bag.addEnd(everyParsedPatient)
                std::vector<std::string> PatientsInBagAsStrings;
                char *str = const_cast<char *>(gameData.at(i).c_str());

                // Returns first token
                char *token = strtok(str, ", ");

                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != NULL)
                {
                    PatientsInBagAsStrings.push_back(token);

                    token = strtok(NULL, ", ");
                }

                int PatientCount = PatientsInBagAsStrings.size();

                for (int i = 0; i < PatientCount; i++)
                {
                    Ward ward = PatientsInBagAsStrings.at(i).at(0);
                    Shape shape = PatientsInBagAsStrings.at(i).at(1);
                    Patient *Patient = new Patient(ward, shape);
                    bag->addEnd(Patient);
                }
            }
            if (i == 10)
            {
                currentPlayerName = &gameData.at(i);
            }
        }
    }

    inputFile.close();
    return true;
}

Register DataHandler::getRegister()
{
    return *(this->board);
}

// Saves data to a file & from relevent variables
//  assumtion is that the data is in the correct format file is in a valid format
// file needs to be opened or created
bool DataHandler::saveData(char *&players)
{

    // std::cout << player3->getName().length() << "\n";

    std::ofstream outputFile(*filename);
    std::string numToPlayString = "";
    numToPlayString.append(1, *players);
    outputFile << numToPlayString << std::endl;
    outputFile << player1->getName() << std::endl;
    outputFile << player1->getScore() << std::endl;
    outputFile << handAsString(player1) << std::endl;
    outputFile << player2->getName() << std::endl;
    outputFile << player2->getScore() << std::endl;
    outputFile << handAsString(player2) << std::endl;
    if (*players == '3')
    {
        outputFile << player3->getName() << std::endl;
        outputFile << player3->getScore() << std::endl;
        outputFile << handAsString(player3) << std::endl;
    }
    else if (*players == '4')
    {

        outputFile << player3->getName() << std::endl;
        outputFile << player3->getScore() << std::endl;
        outputFile << handAsString(player3) << std::endl;
        outputFile << player4->getName() << std::endl;
        outputFile << player4->getScore() << std::endl;
        outputFile << handAsString(player4) << std::endl;
    }
    outputFile << boardShapeAsString(board) << std::endl;
    outputFile << setRegisterStateAsString(board) << std::endl;
    outputFile << bagContentsAsString(bag) << std::endl;
    outputFile << *currentPlayerName << std::endl;

    outputFile.close();

    // loadData(*filename);

    return true;
}

void DataHandler::setPlayer1(Player *&player1)
{
    this->player1 = player1;
}

void DataHandler::setPlayer2(Player *&player2)
{
    this->player2 = player2;
}

void DataHandler::setPlayer3(Player *&player3)
{
    this->player3 = player3;
}

void DataHandler::setPlayer4(Player *&player4)
{
    this->player4 = player4;
}
void DataHandler::setRegister(Register *&board)
{
    this->board = board;
}

void DataHandler::setBag(LinkedList *&bag)
{
    this->bag = bag;
}

void DataHandler::setCurrentPlayerName(std::string *&currentPlayerName)
{
    this->currentPlayerName = currentPlayerName;
}

void DataHandler::setFilename(std::string *&filename)
{
    this->filename = filename;
}
void DataHandler::setNumToPlay(char numToPlay)
{

    *this->numToPlayLoaded = numToPlay;
}

std::string DataHandler::handAsString(Player *&player)
{
    std::string handAsString = "";
    LinkedList *hand = nullptr;
    if (player->getHand() != nullptr)
    {
        hand = player->getHand();
    }
    else
    {
        std::cout << "WHY is Player::getHand() a nullptr?" << std::endl;
    }

    int count = 0;
    int hand_size = hand->getLength();
    for (int i = 0; i < hand_size; i++)
    {
        Node *node = hand->getNodeByIndex(i);
        Patient *Patient = node->getData();
        if (Patient != nullptr)
        {
            // std::cout << "Patient != nullptr" << std::endl;

            Ward ward = Patient->getWard();
            Shape shape = Patient->getShape();
            handAsString.push_back(ward);
            handAsString.push_back(shape + ASCII_NUMERIC_OFFSET);

            count++;
        }
        else
        {
            // std::cout << "Patient == nullptr" << std::endl;
        }

        if (count < hand_size)
        {
            handAsString.append(",");
        }
    }
    return handAsString;
}

std::string DataHandler::boardShapeAsString(Register *&board)
{
    std::string boardShape = "";
    std::string heightAsString = std::to_string(ROW_COUNT);
    std::string widthAsString = std::to_string(COL_COUNT);

    boardShape.append(heightAsString);
    boardShape.append(",");
    boardShape.append(widthAsString);

    return boardShape;
}

std::string DataHandler::setRegisterStateAsString(Register *&board)
{
    std::string boardState = "";

    // Build string tokens of <Ward><Shape>@<Row><Column>
    std::vector<std::string> PatientsWithCoords;
    for (int row = 0; row < ROW_COUNT; row++)
    {
        for (int column = 0; column < COL_COUNT; column++)
        {
            Patient *Patient = board->getPatientAt(row, column);
            if (Patient != nullptr)
            {
                // Building a WardShape@RowColumn string
                Ward ward = Patient->getWard();
                Shape shape = Patient->getShape();
                char rowAsChar = row + ASCII_ALPHABET_OFFSET;
                std::string columnAsString = std::to_string(column);
                std::string PatientText = "";
                PatientText.push_back(ward);
                PatientText.push_back(shape + ASCII_NUMERIC_OFFSET);
                PatientText.push_back('@');
                PatientText.push_back(rowAsChar);
                // PatientText.push_back(columnAsChar);
                PatientText.append(columnAsString);

                // Append to local vector<string>
                PatientsWithCoords.push_back(PatientText);
            }
        }
    }

    int PatientCount = PatientsWithCoords.size();
    int count = 0;

    for (int i = 0; i < PatientCount; i++)
    {
        boardState.append(PatientsWithCoords.at(i));
        count++;
        if (count < PatientCount)
        {
            boardState.append(", ");
        }
    }

    return boardState;
}

std::string DataHandler::bagContentsAsString(LinkedList *&bag)
{
    std::string bagContents = "";
    if (bag != nullptr)
    {
        int count = 0;
        int bag_size = bag->getLength();
        for (int i = 0; i < bag_size; i++)
        {
            Node *node = bag->getNodeByIndex(i);
            Patient *Patient = node->getData();
            if (Patient != nullptr)
            {
                // std::cout << "Patient != nullptr" << std::endl;

                Ward ward = Patient->getWard();
                Shape shape = Patient->getShape();
                bagContents.push_back(ward);
                bagContents.push_back(shape + ASCII_NUMERIC_OFFSET);

                count++;
            }
            else
            {
                // std::cout << "Patient == nullptr" << std::endl;
            }

            if (count < bag_size)
            {
                bagContents.append(",");
            }
        }
    }
    else
    {
        std::cout << "WHY is bag a nullptr?" << std::endl;
    }

    return bagContents;
}

std::string DataHandler::getPlayer1Name()
{
    std::string player1name = "";
    if (player1 != nullptr)
    {
        player1name = player1->getName();
    }

    return player1name;
}

std::string DataHandler::getPlayer2Name()
{
    std::string player2name = "";
    if (player2 != nullptr)
    {
        player2name = player2->getName();
    }

    return player2name;
}
std::string DataHandler::getPlayer4Name()
{
    std::string player4name = "";
    if (player4 != nullptr)
    {
        player4name = player4->getName();
    }

    return player4name;
}
std::string DataHandler::getPlayer3Name()
{
    std::string player3name = "";
    if (player3 != nullptr)
    {
        player3name = player3->getName();
    }

    return player3name;
}

void DataHandler::fillBagWithSavedPatients(LinkedList *&bag)
{
}

void DataHandler::fillPlayer1HandWithSavedPatients(LinkedList *&hand)
{
    Node *temp = player1->getHand()->getHead();

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            temp = temp->getNext();

            hand->addEnd(player1->getHand()->removeFront());
        }
    }
}

void DataHandler::fillPlayer2HandWithSavedPatients(LinkedList *&hand)
{
    Node *temp = player2->getHand()->getHead();

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            temp = temp->getNext();

            hand->addEnd(player2->getHand()->removeFront());
        }
    }
}
void DataHandler::fillPlayer3HandWithSavedPatients(LinkedList *&hand)
{
    Node *temp = player3->getHand()->getHead();

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            temp = temp->getNext();

            hand->addEnd(player3->getHand()->removeFront());
        }
    }
}
void DataHandler::fillPlayer4HandWithSavedPatients(LinkedList *&hand)
{
    Node *temp = player4->getHand()->getHead();

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            temp = temp->getNext();

            hand->addEnd(player4->getHand()->removeFront());
        }
    }
}

int DataHandler::getPlayer1Score()
{
    int player1_score = this->player1->getScore();
    return player1_score;
}

int DataHandler::getPlayer2Score()
{
    int player2_score = this->player2->getScore();
    return player2_score;
}

int DataHandler::getPlayer3Score()
{
    int player3_score = this->player3->getScore();
    return player3_score;
}

int DataHandler::getPlayer4Score()
{
    int player4_score = this->player4->getScore();
    return player4_score;
}

int DataHandler::getRegisterHeight()
{
    int boardHeight;
    boardHeight = 26;

    return boardHeight;
}

int DataHandler::getRegisterWidth()
{
    int boardWidth;
    boardWidth = 26;

    return boardWidth;
}

std::string DataHandler::getCurrentPlayerName()
{
    std::string playername = "";
    if (currentPlayerName != nullptr)
    {
        playername = *currentPlayerName;
    }
    else
    {
    }
    return playername;
}

char DataHandler::getNumToPlayLoaded()
{
    return *numToPlayLoaded;
}