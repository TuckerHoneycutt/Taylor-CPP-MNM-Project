#include "Character.h"

// Default constructor
Character::Character() : m_iClass(0), m_iAlignment(0), m_iHitPoints(0), m_itemCount(0), m_pNext(nullptr)
{
    // Initialize m_sName to empty string
    m_sName[0] = '\0';

    // Initialize character traits to 0
    for (int i = 0; i < 6; ++i) {
        m_iCharTraits[i] = 0;
    }

    // Initialize item array to nullptr
    for (int i = 0; i < MAX_ITEMS; ++i) {
        m_itemArray[i] = nullptr;
    }
}

// Parameterized constructor
Character::Character(char *name, int clas, int alignment, int hitpoints, int strength,
                     int dexterity, int constitution, int intelligence, int wisdom,
                     int charisma) : m_iClass(clas), m_iAlignment(alignment),
                                     m_iHitPoints(hitpoints), m_itemCount(0)
{
    strncpy(m_sName, name, 64);
    m_sName[64] = '\0';  // Ensure null-termination
    m_iCharTraits[0] = strength;
    m_iCharTraits[1] = dexterity;
    m_iCharTraits[2] = constitution;
    m_iCharTraits[3] = intelligence;
    m_iCharTraits[4] = wisdom;
    m_iCharTraits[5] = charisma;
    for (int i = 0; i < MAX_ITEMS; i++) {
        m_itemArray[i] = nullptr;
    }
    m_pNext = nullptr;
}

// Destructor
Character::~Character()
{
    for (int i = 0; i < m_itemCount; i++) {
        delete m_itemArray[i];
    }
}

// Get the character's name
char* Character::getName()
{
    return m_sName;
}

// Set the character's name
void Character::setName(char *name)
{
    strncpy(m_sName, name, 64);
    m_sName[64] = '\0';  // Ensure null-termination
}

// Get the character's class
int Character::getClass()
{
    return m_iClass;
}

// Set the character's class
void Character::setClass(int cl)
{
    m_iClass = cl;
}

// Get the character's alignment
int Character::getAlignment()
{
    return m_iAlignment;
}

// Set the character's alignment
void Character::setAlignment(int al)
{
    m_iAlignment = al;
}

// Get the character's hit points
int Character::getHitPoints()
{
    return m_iHitPoints;
}

// Set the character's hit points
void Character::setHitPoints(int hp)
{
    m_iHitPoints = hp;
}

// Get the character's strength
int Character::getStrength()
{
    return m_iCharTraits[0];
}

// Set the character's strength
void Character::setStrength(int str)
{
    m_iCharTraits[0] = str;
}

// Get the character's dexterity
int Character::getDexterity()
{
    return m_iCharTraits[1];
}

// Set the character's dexterity
void Character::setDexterity(int dex)
{
    m_iCharTraits[1] = dex;
}

// Get the character's constitution
int Character::getConstitution()
{
    return m_iCharTraits[2];
}

// Set the character's constitution
void Character::setConstitution(int cn)
{
    m_iCharTraits[2] = cn;
}

// Get the character's intelligence
int Character::getIntelligence()
{
    return m_iCharTraits[3];
}

// Set the character's intelligence
void Character::setIntelligence(int itl)
{
    m_iCharTraits[3] = itl;
}

// Get the character's wisdom
int Character::getWisdom()
{
    return m_iCharTraits[4];
}

// Set the character's wisdom
void Character::setWisdom(int wis)
{
    m_iCharTraits[4] = wis;
}

// Get the character's charisma
int Character::getCharisma()
{
    return m_iCharTraits[5];
}

// Set the character's charisma
void Character::setCharisma(int chr)
{
    m_iCharTraits[5] = chr;
}

// Add an item to the character's inventory
bool Character::addItem(Item *item)
{
    for(int i=0; i<MAX_ITEMS; i++)
    {
        if(m_itemArray[i] == nullptr)
        {
            m_itemArray[i] = new Item(*item);  // Create a new Item object
            return true;
        }
    }
    return false;  // No empty slot found
}

Item* Character::getItem(char* itemName)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (m_itemArray[i] && strcmp(m_itemArray[i]->m_sItemName, itemName) == 0)
        {
            return m_itemArray[i];
        }
    }
    return nullptr;
}

// Remove and return an item from the character's inventory
Item* Character::dropItem(char* itemName)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (m_itemArray[i] && strcmp(m_itemArray[i]->m_sItemName, itemName) == 0)
        {
            Item* droppedItem = m_itemArray[i];
            m_itemArray[i] = nullptr;
            return droppedItem;
        }
    }
    return nullptr;
}


// Print all information about the character
void Character::printAll()
{
    std::cout << "Name: " << m_sName << std::endl;
    std::cout << "Class: " << m_iClass << std::endl;
    std::cout << "Alignment: " << m_iAlignment << std::endl;
    std::cout << "Hit Points: " << m_iHitPoints << std::endl;
    std::cout << "Strength: " << m_iCharTraits[0] << std::endl;
    std::cout << "Dexterity: " << m_iCharTraits[1] << std::endl;
    std::cout << "Constitution: " << m_iCharTraits[2] << std::endl;
    std::cout << "Intelligence: " << m_iCharTraits[3] << std::endl;
    std::cout << "Wisdom: " << m_iCharTraits[4] << std::endl;
    std::cout << "Charisma: " << m_iCharTraits[5] << std::endl;

    for(int i=0; i<MAX_ITEMS; i++)
    {
        if(m_itemArray[i] != nullptr)
        {
            std::cout << "  Item " << i+1 << ": " << m_itemArray[i]->m_sItemName << std::endl;
        }
    }
}
