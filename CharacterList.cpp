#include "CharacterList.h"
#include <cstring>

CharacterList::CharacterList() : m_pHead(nullptr) {}

CharacterList::~CharacterList() {
    while (m_pHead) {
        Character* temp = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete temp;
    }
}

bool CharacterList::addCharacter(Character* newCharacter) {
    if (!newCharacter) return false;

    if (!m_pHead || strcmp(newCharacter->getName(), m_pHead->getName()) < 0) {
        newCharacter->m_pNext = m_pHead;
        m_pHead = newCharacter;
        return true;
    }

    Character* current = m_pHead;
    while (current->m_pNext && strcmp(newCharacter->getName(), current->m_pNext->getName()) > 0) {
        current = current->m_pNext;
    }

    newCharacter->m_pNext = current->m_pNext;
    current->m_pNext = newCharacter;
    return true;
}

Character* CharacterList::deleteCharacter(char* characterName) {
    if (!m_pHead) return nullptr;

    if (strcmp(m_pHead->getName(), characterName) == 0) {
        Character* deletedCharacter = m_pHead;
        m_pHead = m_pHead->m_pNext;
        deletedCharacter->m_pNext = nullptr;
        return deletedCharacter;
    }

    Character* current = m_pHead;
    while (current->m_pNext && strcmp(current->m_pNext->getName(), characterName) != 0) {
        current = current->m_pNext;
    }

    if (current->m_pNext) {
        Character* deletedCharacter = current->m_pNext;
        current->m_pNext = deletedCharacter->m_pNext;
        deletedCharacter->m_pNext = nullptr;
        return deletedCharacter;
    }

    return nullptr;
}

bool CharacterList::addItem(char* characterName, Item* newItem) {
    Character* character = m_pHead;
    while (character && strcmp(character->getName(), characterName) != 0) {
        character = character->m_pNext;
    }

    if (character) {
        return character->addItem(newItem);
    }

    return false;
}

Item* CharacterList::getItem(char* characterName, char* itemName)
{
    Character* character = m_pHead;
    while (character && strcmp(character->getName(), characterName) != 0)
    {
        character = character->m_pNext;
    }

    if (character)
    {
        return character->getItem(itemName);
    }

    return nullptr;
}

Item* CharacterList::dropItem(char* characterName, char* itemName)
{
    Character* character = m_pHead;
    while (character && strcmp(character->getName(), characterName) != 0)
    {
        character = character->m_pNext;
    }

    if (character)
    {
        return character->dropItem(itemName);
    }

    return nullptr;
}

void CharacterList::printCharacters() {
    Character* current = m_pHead;
    while (current) {
        current->printAll();
        current = current->m_pNext;
    }
}
