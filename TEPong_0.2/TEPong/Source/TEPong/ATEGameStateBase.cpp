 // Fill out your copyright notice in the Description page of Project Settings.
#include "ATEGameStateBase.h"

AATEGameStateBase::AATEGameStateBase()
{

}

int AATEGameStateBase::GetNumberOfLeftGoals()
{
	return NumberOfLeftGoals;
}

int AATEGameStateBase::GetNumberOfRightGoals()
{
	return NumberOfRightGoals;
}