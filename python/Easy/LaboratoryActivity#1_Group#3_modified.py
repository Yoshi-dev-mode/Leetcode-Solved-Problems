"""
=========================================================
       INVENTORY AND STOCK MANAGEMENT SYSTEM
=========================================================

Description:
    This program is a menu-driven Inventory and Stock
    Management System for a small computer parts store.

    It uses a Python list as a dynamic array to store
    stock quantities. The program allows the user to
    add, update, delete, search, sort, analyze, and
    manage inventory records.

Low-stock rule:
    A stock quantity below 30 units is considered
    LOW STOCK.

Initial Stock:
    [50, 20, 90, 16, 60, 30, 100]

Developed by:
    1. Evangel Yoshiya G. Aranas
    2. Janver P. Manlapaz
    3. Ken Austine M. Fajutag

=========================================================
"""


class Inventory:
    """
    Inventory class

    This class manages the stock quantities of the store.
    The self.items list acts as a dynamic array where
    all inventory records are stored.
    """

    def __init__(self):
        # Initial stock quantities
        self.items = [50, 20, 90, 16, 60, 30, 100]

    # -----------------------------------------------------
    # 1. DISPLAY ALL STOCK QUANTITIES
    # -----------------------------------------------------
    def display(self):
        """Display all stock quantities with their indexes."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        print("\nStock Quantities:")

        for i in range(len(self.items)):
            print("Index", i, ":", self.items[i])

    # -----------------------------------------------------
    # 2. ACCESS STOCK USING INDEX
    # -----------------------------------------------------
    def access(self, index):
        """Access and display a stock quantity using its index."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        # Check if the index is valid
        if 0 <= index < len(self.items):
            print("Stock at index", index, ":", self.items[index])
        else:
            print("Invalid index.")

    # -----------------------------------------------------
    # 3. ADD A NEW STOCK QUANTITY
    # -----------------------------------------------------
    def add(self, quantity):
        """Add a new stock quantity at the end of the array."""

        self.items.append(quantity)

        print("Stock quantity added successfully.")
        print("Updated stocks:", self.items)

    # -----------------------------------------------------
    # 4. INSERT STOCK AT A SPECIFIC POSITION
    # -----------------------------------------------------
    def insert(self, position, quantity):
        """Insert a stock quantity at a specific index."""

        # A position equal to len(items) is also valid
        if 0 <= position <= len(self.items):
            self.items.insert(position, quantity)

            print("Stock inserted successfully.")
            print("Updated stocks:", self.items)
        else:
            print("Invalid position.")

    # -----------------------------------------------------
    # 5. UPDATE STOCK QUANTITY
    # -----------------------------------------------------
    def update(self, index, quantity):
        """Replace the stock quantity at a specific index."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        if 0 <= index < len(self.items):

            # Replace the old value with the new value
            self.items[index] = quantity

            print("Stock updated successfully.")
            print("Updated stocks:", self.items)

        else:
            print("Invalid index.")

    # -----------------------------------------------------
    # 6. DELETE STOCK BY POSITION
    # -----------------------------------------------------
    def delete_by_position(self, index):
        """Delete a stock quantity using its index."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        if 0 <= index < len(self.items):

            # pop() removes and returns the item at the index
            deleted = self.items.pop(index)

            print("Deleted stock:", deleted)
            print("Updated stocks:", self.items)

        else:
            print("Invalid index.")

    # -----------------------------------------------------
    # 7. DELETE A SPECIFIC STOCK QUANTITY
    # -----------------------------------------------------
    def delete_by_value(self, quantity):
        """Delete the first occurrence of a specific quantity."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        if quantity in self.items:

            # remove() deletes the first matching value
            self.items.remove(quantity)

            print("Stock quantity deleted successfully.")
            print("Updated stocks:", self.items)

        else:
            print("Stock quantity not found.")

    # -----------------------------------------------------
    # 8. SEARCH FOR A STOCK QUANTITY
    # -----------------------------------------------------
    def search(self, quantity):
        """Search for a stock quantity and display its index."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        if quantity in self.items:

            # index() returns the first occurrence
            index = self.items.index(quantity)

            print("Stock quantity found.")
            print("Index:", index)

        else:
            print("Stock quantity not found.")

    # -----------------------------------------------------
    # 9. SORT STOCKS IN ASCENDING ORDER
    # -----------------------------------------------------
    def sort_ascending(self):
        """Sort the stock quantities from lowest to highest."""

        self.items.sort()

        print("Stocks sorted in ascending order.")
        print("Updated stocks:", self.items)

    # -----------------------------------------------------
    # 10. SORT STOCKS IN DESCENDING ORDER
    # -----------------------------------------------------
    def sort_descending(self):
        """Sort the stock quantities from highest to lowest."""

        self.items.sort(reverse=True)

        print("Stocks sorted in descending order.")
        print("Updated stocks:", self.items)

    # -----------------------------------------------------
    # 11. REVERSE STOCK RECORDS
    # -----------------------------------------------------
    def reverse(self):
        """Reverse the order of the inventory records."""

        self.items.reverse()

        print("Stock records reversed.")
        print("Updated stocks:", self.items)

    # -----------------------------------------------------
    # 12. FIND HIGHEST STOCK QUANTITY
    # -----------------------------------------------------
    def highest(self):
        """Find and display the highest stock quantity."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        print("Highest stock quantity:", max(self.items))

    # -----------------------------------------------------
    # 13. FIND LOWEST STOCK QUANTITY
    # -----------------------------------------------------
    def lowest(self):
        """Find and display the lowest stock quantity."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        print("Lowest stock quantity:", min(self.items))

    # -----------------------------------------------------
    # 14. CALCULATE TOTAL NUMBER OF STOCKS
    # -----------------------------------------------------
    def total(self):
        """Calculate the total quantity of all stocks."""

        print("Total number of stocks:", sum(self.items))

    # -----------------------------------------------------
    # 15. CALCULATE AVERAGE STOCK QUANTITY
    # -----------------------------------------------------
    def average(self):
        """Calculate the average stock quantity."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        average = sum(self.items) / len(self.items)

        print("Average stock quantity:", average)

    # -----------------------------------------------------
    # 16. COUNT OCCURRENCE OF A STOCK QUANTITY
    # -----------------------------------------------------
    def count(self, quantity):
        """Count how many times a stock quantity occurs."""

        occurrence = self.items.count(quantity)

        print(quantity, "occurs", occurrence, "time(s).")

    # -----------------------------------------------------
    # 17. DISPLAY NUMBER OF INVENTORY RECORDS
    # -----------------------------------------------------
    def size(self):
        """Display the total number of inventory records."""

        print("Number of inventory records:", len(self.items))

    # -----------------------------------------------------
    # 18. DISPLAY LOW-STOCK AND SUFFICIENT-STOCK ITEMS
    # -----------------------------------------------------
    def stock_status(self):
        """
        Display which inventory records are low stock
        and which have sufficient stock.

        Low stock = below 30 units
        Sufficient stock = 30 units or more
        """

        if self.is_empty():
            print("Inventory is empty.")
            return

        print("\nLOW-STOCK ITEMS")
        print("----------------")

        found_low = False

        # Check every stock quantity
        for i in range(len(self.items)):

            if self.items[i] < 30:
                print("Index", i, ":", self.items[i])
                found_low = True

        if not found_low:
            print("No low-stock items.")

        print("\nSUFFICIENT-STOCK ITEMS")
        print("----------------------")

        found_sufficient = False

        for i in range(len(self.items)):

            if self.items[i] >= 30:
                print("Index", i, ":", self.items[i])
                found_sufficient = True

        if not found_sufficient:
            print("No sufficient-stock items.")

    # -----------------------------------------------------
    # 19. RESTOCK ALL LOW-STOCK ITEMS
    # -----------------------------------------------------
    def restock(self, amount):
        """
        Add the specified amount to every stock quantity
        that is below 30 units.
        """

        if self.is_empty():
            print("Inventory is empty.")
            return

        for i in range(len(self.items)):

            # Low-stock items are below 30
            if self.items[i] < 30:

                # Add the restock amount
                self.items[i] += amount

        print("All low-stock items have been restocked.")
        print("Updated stocks:", self.items)

    # -----------------------------------------------------
    # 20. DISPLAY INVENTORY STATISTICS
    # -----------------------------------------------------
    def statistics(self):
        """Display important statistics about the inventory."""

        if self.is_empty():
            print("Inventory is empty.")
            return

        total = sum(self.items)
        average = total / len(self.items)
        highest = max(self.items)
        lowest = min(self.items)

        # Counters for stock status
        low_stock = 0
        sufficient_stock = 0

        for stock in self.items:

            if stock < 30:
                low_stock += 1
            else:
                sufficient_stock += 1

        print("\n========== INVENTORY STATISTICS ==========")
        print("Number of records:", len(self.items))
        print("Total stock:", total)
        print("Average stock:", average)
        print("Highest stock:", highest)
        print("Lowest stock:", lowest)
        print("Low-stock items:", low_stock)
        print("Sufficient-stock items:", sufficient_stock)
        print("==========================================")

    # -----------------------------------------------------
    # 21. CLEAR INVENTORY
    # -----------------------------------------------------
    def clear(self):
        """Remove all inventory records."""

        self.items.clear()

        print("Inventory cleared.")
        print("Current stocks:", self.items)

    # -----------------------------------------------------
    # CHECK IF INVENTORY IS EMPTY
    # -----------------------------------------------------
    def is_empty(self):
        """Return True if there are no inventory records."""

        return len(self.items) == 0


# =========================================================
# CREATE INVENTORY OBJECT
# =========================================================

inventory = Inventory()


# =========================================================
# MAIN MENU
# =========================================================

while True:

    print("\n========================================")
    print("   INVENTORY AND STOCK MANAGEMENT SYSTEM")
    print("========================================")
    print("1. Display all stock quantities")
    print("2. Access stock using index")
    print("3. Add a new stock quantity")
    print("4. Insert stock at a specific position")
    print("5. Update stock quantity")
    print("6. Delete stock by position")
    print("7. Delete a specific stock quantity")
    print("8. Search for a stock quantity")
    print("9. Sort stocks in ascending order")
    print("10. Sort stocks in descending order")
    print("11. Reverse stock records")
    print("12. Find highest stock quantity")
    print("13. Find lowest stock quantity")
    print("14. Calculate total number of stocks")
    print("15. Calculate average stock quantity")
    print("16. Count occurrence of a stock quantity")
    print("17. Display number of inventory records")
    print("18. Display low-stock and sufficient-stock items")
    print("19. Restock all low-stock items")
    print("20. Display inventory statistics")
    print("21. Clear inventory")
    print("22. Exit")
    print("========================================")

    choice = int(input("Enter your choice: "))


    # -----------------------------------------------------
    # PROCESS USER'S MENU CHOICE
    # -----------------------------------------------------

    if choice == 1:
        inventory.display()

    elif choice == 2:
        index = int(input("Enter index: "))
        inventory.access(index)

    elif choice == 3:
        quantity = int(input("Enter new stock quantity: "))
        inventory.add(quantity)

    elif choice == 4:
        position = int(input("Enter position: "))
        quantity = int(input("Enter stock quantity: "))
        inventory.insert(position, quantity)

    elif choice == 5:
        index = int(input("Enter index: "))
        quantity = int(input("Enter new stock quantity: "))
        inventory.update(index, quantity)

    elif choice == 6:
        index = int(input("Enter index to delete: "))
        inventory.delete_by_position(index)

    elif choice == 7:
        quantity = int(input("Enter stock quantity to delete: "))
        inventory.delete_by_value(quantity)

    elif choice == 8:
        quantity = int(input("Enter stock quantity to search: "))
        inventory.search(quantity)

    elif choice == 9:
        inventory.sort_ascending()

    elif choice == 10:
        inventory.sort_descending()

    elif choice == 11:
        inventory.reverse()

    elif choice == 12:
        inventory.highest()

    elif choice == 13:
        inventory.lowest()

    elif choice == 14:
        inventory.total()

    elif choice == 15:
        inventory.average()

    elif choice == 16:
        quantity = int(input("Enter stock quantity: "))
        inventory.count(quantity)

    elif choice == 17:
        inventory.size()

    elif choice == 18:
        inventory.stock_status()

    elif choice == 19:
        amount = int(input("Enter restock amount: "))
        inventory.restock(amount)

    elif choice == 20:
        inventory.statistics()

    elif choice == 21:
        inventory.clear()

    elif choice == 22:
        # Exit message with the names of the developers
        print("\n========================================")
        print("Thank you for using our Inventory System!")
        print("========================================")
        print("Developed by:")
        print("Evangel Yoshiya G. Aranas")
        print("Janver P. Manlapaz")
        print("Ken Austine M. Fajutag")
        print("\nThank you and have a great day!")
        print("========================================")

        break

    else:
        print("Invalid choice. Please select 1-22.")
