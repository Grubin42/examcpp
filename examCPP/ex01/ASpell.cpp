#include "ASpell.hpp"
#include "ATarget.hpp"

void ASpell::launch(const ATarget & atarget) const
{
    atarget.getHitBySpell(*this);
}