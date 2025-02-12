#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

# Test function
test_numbers() {
    COUNT=$1
    TESTS=$2
    MAX_MOVES=$3
    
    echo -e "${BLUE}Testing with $COUNT numbers ($TESTS tests, max $MAX_MOVES moves)${NC}"
    
    for i in $(seq 1 $TESTS); do
        ARG=$(seq 1 $COUNT | shuf | tr '\n' ' ')
        MOVES=$(./push_swap $ARG | wc -l)
        VALID=$(./push_swap $ARG | ./checker_linux $ARG)
        
        if [ "$VALID" = "OK" ] && [ $MOVES -le $MAX_MOVES ]; then
            echo -e "${GREEN}Test $i: OK ($MOVES moves)${NC}"
        else
            echo -e "${RED}Test $i: KO ($MOVES moves)${NC}"
        fi
    done
}

# Main tests
echo "=== Push Swap Tests ==="
test_numbers 100 5 700    # Test with 100 numbers, max 700 moves
test_numbers 500 5 5500   # Test with 500 numbers, max 5500 moveschmod +x test.sh