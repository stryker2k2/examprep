import unittest, test_cases

if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromModule(test_cases)
    unittest.TextTestRunner(verbosity=2).run(suite)