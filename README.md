# Taxi Service Simulation
This C++ project simulates a taxi service system with randomized driver assignments, trip pricing, and user feedback collection.

## Key Features Taxi Assignment System:

Randomly selects drivers from a "names_database.txt"

Randomly assigns vehicles from a "cars_database.txt"

Generates random driver experience (1-30 years)

Calculates driver ratings (1.0-5.0 with 0.1 precision)

Trip Management:

Generates random trip distances (10,000-100,000 units)

Calculates trip cost based on distance (30% of distance)

Displays comprehensive trip information

User Feedback System:

Collects star ratings (1-5)

Gathers qualitative feedback based on rating

Provides appropriate responses to different rating levels

Data Persistence:

Saves all interactions to "save_database.txt"

Maintains logs of taxi assignments and feedback

Technical Implementation
Object-oriented design with Taxi class

File I/O operations for name/car databases

Random number generation for realistic simulation

Stream handling for both console and file output

User interaction through console menu

How It Works
Users can call a taxi, which generates a random driver/car assignment

Users can view driver information (experience, rating)

Users can leave feedback about their trip

All interactions are logged to a file

The system demonstrates core programming concepts including file handling, random number generation, object-oriented programming, and user interaction patterns.
