## Testing

The Smart Ventilation Controller was manually tested using multiple temperature scenarios to ensure that it was working properly.

| Test Case | Inside Temperature | Outside Temperature | Expected Result | Result |
|-----------|-------------------|--------------------|-----------------|--------|
| Cooler outside air | 22.5 C | 18 C | Ventilation ON | Passed |
| Warmer outside air | 22.5 C | 30 C | Ventilation OFF | Passed |
| Equal temperatures | 22.5 C | 22.5 C | Ventilation OFF | Passed |
| Negative temperature input | 22.5 C | -10 C | Accepted | Passed |
| Unrealistic temperature (above high end) | 20 C | 62 C | Rejected | Passed |
| Unrealistic temperature (below low end)| 20 C | -42 C | Rejected | Passed |
| Invalid input | 20 C | "abc" | Rejected | Passed |
| Sensor Read Failure | Couldn't detect | -- | Rejected | Passed |

All these test cases passed. The controller properly handled valid operating conditions, invalid user input, unrealistic temperature values, and sensor read failures.
