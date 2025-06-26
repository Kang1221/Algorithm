import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] days = new int[speeds.length];
        for(int i=0; i<speeds.length; i++){
            days[i] = (100 - progresses[i])/speeds[i];
            if((100 - progresses[i])%speeds[i] != 0){
                days[i]++;
            }
        }
        
        List<Integer> answer = new ArrayList<>();
        int count = 0, prev = days[0];
        for(int day : days){
            if(day > prev){
                answer.add(count);
                prev = day;
                count = 1;
            }
            else{
                count++;
            }
        }
        answer.add(count);
        return answer.stream().mapToInt(i->i).toArray();
    }
}
