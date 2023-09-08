#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  int healthy=0,exchange=0,failed=0;
  for(int i=0;i<nBatteries;i++)
    {
      float soh=(100*1.0*presentCapacities[i])/120.0;
      if(soh>80)
        healthy++;
      else if(soh>65)
        exchange++;
      else
        failed++;
    }
  struct CountsBySoH counts = {healthy, exchange, failed};
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {115, 118, 80, 95, 91, 77};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
