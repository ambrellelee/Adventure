#ifndef ITEM_HPP
#define ITEM_HPP

struct Item                   //holds information about items in room
{
        std::string iName;
        std::string iDesc;
        std::string useDesc;
        int waterLevel;
        int maxWater;
        bool available;
        int featureSource;
        int whenCanTake;
        Item(std::string newItemName, std::string newItemDesc, std::string newItemUse, int waterU, int waterMax, bool canPickUp, int featureIndex, int interactionNum)
        {
                iName = newItemName;
                iDesc = newItemDesc;
                useDesc = newItemUse;
                waterLevel = waterU;
                maxWater = waterMax;
                available = canPickUp;
                featureSource = featureIndex;
                whenCanTake = interactionNum;
        }
};

#endif
