## Testing

The Smart Ventilation Controller was tested using multiple temperature scenarios to verify correct ventilation behavior.

| Test Case | Inside Temperature | Outside Temperature | Expected Result | Result |
|-----------|-------------------|--------------------|-----------------|--------|
| Cooler outside air | 22.5 C | 18 C | Ventilation ON | Passed |
| Warmer outside air | 22.5 C | 30 C | Ventilation OFF | Passed |
| Equal temperatures | 22.5 C | 22.5 C | Ventilation OFF | Passed |
| Negative temperature input | 22.5 C | -10 C | Accepted | Passed |
| Unrealistic temperature | 20 C | 55 C | Rejected | Passed |
| Invalid input | 20 C | "abc" | Rejected | Passed |
