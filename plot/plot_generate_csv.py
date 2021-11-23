#!/usr/bin/python
# -*- coding: utf-8 -*-
"""
Mamdani Fuzzy Inference System.

Copyright (c) 2021, Augusto Damasceno.
All rights reserved. 
"""

__author__ = "Augusto Damasceno (augustodamasceno@protonmail.com)"
__version__ = "0.2"
__copyright__ = "Copyright (c) 2021 Augusto Damasceno"
__license__ = "2-Clause BSD License"

if __name__ == "__main__":
    import pandas as pd
    import matplotlib.pyplot as plt
    from os.path import exists
    import sys

    ERROR_NO_CSV_FILE = 1
    ERROR_NO_PERMISSION = 2
    ERROR_DF_READ_CSV = 3

    csv_exists = True
    if len(sys.argv) > 1 and exists(sys.argv[1]):
        csv_file = sys.argv[1]
    elif exists('../membershipFunctions.csv'):
       csv_file = '../membershipFunctions.csv'
    elif exists('../extras/csv/membershipFunctions.csv'):
        csv_file = '../extras/csv/membershipFunctions.csv'
    else:
        csv_exists = False

    if csv_exists:
        try:
            df = pd.read_csv(csv_file)
            print('From file ', csv_file)
            plt.plot(df['x'], df['Triangle'])
            plt.plot(df['x'], df['Trapezoidal'])
            plt.plot(df['x'], df['Gaussian'])
            plt.legend(['Triangle', 'Trapezoidal', 'Gaussian'])
            plt.title('Membership Functions')
            plt.savefig('Membership_Functions.png', format='png')
            plt.show()
        except PermissionError:
            print('ERROR: Permission denied to read the file ', csv_file)
            sys.exit(ERROR_NO_PERMISSION)
        except Exception as e:
            print('ERROR: ', e, ' with file ', csv_file)
            sys.exit(ERROR_DF_READ_CSV)
    else:
        print('No csv for membership functions founded!')
        sys.exit(ERROR_NO_CSV_FILE)
