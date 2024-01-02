#include "Account.hpp"
#include <time.h>
#include <iostream>
#include <cstdlib>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;

}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;

}

void	Account::displayAccountsInfos( void )
{
    if (Account::_nbAccounts > 0)
    {
        Account::_displayTimestamp();
        std::cout << "accounts:" << Account::getNbAccounts();
        std::cout << ";total:" << Account::getTotalAmount();
        std::cout << ";deposits:" << Account::getNbDeposits();
        std::cout << ";withdrawals:" << Account::getNbWithdrawals();
        std::cout << std::endl;
    }

}
int Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void Account::_displayTimestamp( void )
{
    std::time_t rawtime;
    struct tm	*timeinfo;
	char		buffer[16];

    if (time(&rawtime) == -1)
    {
        std::cout << "Calendar time not available" << std::endl;
        exit(1);
    }
    else
    {
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(buffer, 16, "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "] ";
    }
}



void	Account::makeDeposit( int deposit )
{


    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:" << _amount + deposit;
    std::cout << ";nb_deposits:" << _nbDeposits + 1;
    std::cout << std::endl;

    _amount += deposit;
    _nbDeposits += 1;
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused";
        std::cout << std::endl;
        return (1);
    }
    else
    {
        std::cout << ";withdrawal:" << withdrawal;
        std::cout << ";amount:" << _amount - withdrawal;
        std::cout << ";nb_deposits:" << _nbWithdrawals + 1;
        std::cout << std::endl;
    }
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    Account::_totalNbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    return (0);
}
int		Account::checkAmount( void ) const
{
    return (_amount);
}
void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}
