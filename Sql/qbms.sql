create table if not exists qbms.course
(
    course_id   int auto_increment comment '课程号'
        primary key,
    course_name varchar(20) not null comment '课程名'
);

create table if not exists qbms.chapter
(
    chapter_id   int         not null comment '章节号'
        primary key,
    chapter_name varchar(20) not null,
    course_id    int         not null,
    constraint Chapter_Course
        foreign key (course_id) references qbms.course (course_id)
            on update cascade on delete cascade
);

create table if not exists qbms.examination
(
    examination_id      int unsigned auto_increment
        primary key,
    course_id           int                                 not null,
    examination_time    timestamp default CURRENT_TIMESTAMP not null,
    examination_content varchar(2048)                       not null,
    constraint Examination_Courseid
        foreign key (course_id) references qbms.course (course_id)
            on update cascade on delete cascade
);

create table if not exists qbms.question_type
(
    question_type_id int auto_increment comment '题型号'
        primary key,
    question_name    varchar(20) not null comment '题型名'
);

create table if not exists qbms.question
(
    question_id         int auto_increment
        primary key,
    question_trigger    int       default 0                 not null,
    question_time       timestamp default CURRENT_TIMESTAMP not null,
    question_type_id    int                                 not null,
    question_chapter_id int                                 not null,
    constraint Question_Chapter
        foreign key (question_chapter_id) references qbms.chapter (chapter_id)
            on update cascade on delete cascade,
    constraint Question_QType
        foreign key (question_type_id) references qbms.question_type (question_type_id)
            on update cascade on delete cascade
);

create table if not exists qbms.choice_question
(
    choice_id      int                       not null
        primary key,
    choice_content varchar(255)              not null,
    option1        varchar(255)              not null,
    option2        varchar(255)              not null,
    option3        varchar(255)              not null,
    option4        varchar(255)              not null,
    choice_answer  enum ('A', 'B', 'C', 'D') null,
    constraint Choice_Qid
        foreign key (choice_id) references qbms.question (question_id)
            on update cascade on delete cascade
);

create table if not exists qbms.completion_question
(
    completion_id      int          not null
        primary key,
    completion_content varchar(255) not null,
    completion_answer1 varchar(255) null,
    completion_answer2 varchar(255) null,
    completion_answer3 varchar(255) null,
    completion_answer4 varchar(255) null,
    completion_answer5 varchar(255) null,
    constraint Completion_Qid
        foreign key (completion_id) references qbms.question (question_id)
            on update cascade on delete cascade
);

create table if not exists qbms.examination_question
(
    examination_id int unsigned not null comment '试卷id',
    question_id    int          not null comment '题目id',
    primary key (examination_id, question_id),
    constraint Eid
        foreign key (examination_id) references qbms.examination (examination_id)
            on update cascade on delete cascade,
    constraint Qid
        foreign key (question_id) references qbms.question (question_id)
            on update cascade on delete cascade
)
    charset = utf8;

create definer = root@localhost trigger qbms.qwe
    after insert
    on qbms.examination_question
    for each row
begin
    -- missing source code
end;

create table if not exists qbms.judgment_question
(
    judgment_id      int             not null comment '判断题题号'
        primary key,
    judgment_content varchar(255)    not null comment '判断题内容',
    judgment_answer  enum ('对', '错') null comment '判断题答案',
    constraint Judgment_Qid
        foreign key (judgment_id) references qbms.question (question_id)
            on update cascade on delete cascade
);

create table if not exists qbms.teacher
(
    teacher_id    int          not null comment '教师号'
        primary key,
    teacher_name  varchar(20)  not null comment '教师名',
    teacher_psw   varchar(20)  not null comment '教师登录密码',
    teacher_photo varchar(255) null comment '教师照片'
)
    charset = utf8;

create table if not exists qbms.tc
(
    course  int not null comment '课程号',
    teacher int not null comment '教师号',
    primary key (course, teacher),
    constraint Tcourse_Course
        foreign key (course) references qbms.course (course_id)
            on update cascade on delete cascade,
    constraint Tcourse_Teacher
        foreign key (teacher) references qbms.teacher (teacher_id)
            on update cascade on delete cascade
);

create or replace definer = root@localhost view qbms.asdf as
select distinct `qbms`.`course`.`course_name`          AS `course_name`,
                `qbms`.`question_type`.`question_name` AS `question_name`
from (((`qbms`.`course` join `qbms`.`chapter` on ((`qbms`.`chapter`.`course_id` = `qbms`.`course`.`course_id`))) join `qbms`.`question` on ((
        `qbms`.`question`.`question_chapter_id` = `qbms`.`chapter`.`chapter_id`)))
         join `qbms`.`question_type`
              on ((`qbms`.`question`.`question_type_id` = `qbms`.`question_type`.`question_type_id`)));

-- comment on column qbms.asdf.course_name not supported: 课程名

-- comment on column qbms.asdf.question_name not supported: 题型名


