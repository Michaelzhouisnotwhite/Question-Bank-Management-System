CREATE TRIGGER qwe
AFTER INSERT ON examination_question FOR EACH ROW
begin
 UPDATE question SET question.question_trigger=question.question_trigger+1
  WHERE question.question_id=new.question_id;
END;